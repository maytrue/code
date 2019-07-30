//
// Created by zouguowei on 2019/7/29.
//

#include <map>
#include <iostream>

class LRUCache {
public:

    class ListNode {
    public:

        ListNode(int key, int value) {
            next_ = nullptr;
            pre_ = nullptr;
            key_ = key;
            value_ = value;
        }

        ListNode *pre_;
        ListNode *next_;
        int value_;
        int key_;
    };

    class List {
    public:
        List() {
            head_ = nullptr;
            tail_ = nullptr;
        }

        ListNode* append(int key, int value) {
            ListNode *node = new ListNode(key, value);
            if (!head_) {
                head_ = node;
            }
            if (!tail_) {
                tail_ = node;
            } else {
                tail_->next_ = node;
                node->pre_ = tail_;
                tail_ = node;
            }
            return node;
        }

        void removeHead() {
            if (!head_) {
                return;
            }

            ListNode *node = head_;
            if (head_ == tail_) {
                tail_ = nullptr;
            }
            if (node) {
                head_ = head_->next_;
                if (head_) {
                    head_->pre_ = nullptr;
                }
                delete node;
            }
        }

        int getHeadKey() {
            if (!head_) {
                return -1;
            } else {
                return head_->key_;
            }
        }

        void moveToTail(ListNode *node) {
            if (node == tail_) {
                return;
            }
            ListNode* next = node->next_;
            ListNode* pre = node->pre_;

            if (!pre) {
                head_ = next;
                next->pre_ = nullptr;
            } else {
                pre->next_ = next;
                next->pre_ = pre;
            }
            node->pre_ = tail_;
            node->next_ = nullptr;
            tail_->next_ = node;
            tail_ = node;
        }

        ListNode *head_;
        ListNode *tail_;
    };

    /*
    * @param capacity: An integer
    */
    LRUCache(int capacity) {
        // do intialization if necessary
        max_size_ = capacity;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        if (map_.find(key) != map_.end()) {
            ListNode *node = map_[key];
            list_.moveToTail(node);
            return node->value_;
        } else {
            return -1;
        }
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if (map_.find(key) != map_.end()) {
            ListNode *node = map_[key];
            node->value_ = value;
            list_.moveToTail(node);
        } else {
            if (map_.size() >= max_size_) {
                int head_value = list_.getHeadKey();
                if (head_value != -1) {
                    map_.erase(head_value);
                    list_.removeHead();
                }
            }
            ListNode *node = list_.append(key, value);
            map_[key] = node;
        }
    }

private:
    std::map<int, ListNode*> map_;
    List list_;
    int max_size_;

};

int main(int argc, char *argv[])
{

    {
        auto cache = std::make_shared<LRUCache>(2);
        cache->set(2, 1);
        cache->set(1, 1);
        std::cout << "get(2)" << cache->get(2) << std::endl;

        cache->set(4, 1);
        std::cout << "get(1)" << cache->get(1) << std::endl;
        std::cout << "get(2)" << cache->get(2) << std::endl;
        std::cout << "------" << std::endl;

    }

    {
        auto cache = std::make_shared<LRUCache>(1);
        cache->set(2, 1);
        std::cout << "get(2)" << cache->get(2) << std::endl;
        cache->set(3, 2);

        std::cout << "get(2)" << cache->get(2) << std::endl;
        std::cout << "get(3)" << cache->get(3) << std::endl;
    }

    return 0;
}
