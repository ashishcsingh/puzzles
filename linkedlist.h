#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stack>
#include <list>
#include <unordered_map>
#include <unordered_set>

namespace linkedlist {
using namespace std;
struct Node {
	Node* next_ { nullptr };
	int data_ { 0 };
	Node(int data) :
			data_(data) {
	}
};
void Insert(Node**, int);
bool Delete(Node**, int);
int Length(Node* node);
void Reverse(Node**);
void DeleteVal(Node **head, int val);
void Print(Node**);
void Clear(Node**);
void Split(Node* head, int pivot, Node** lt, Node** gt);
bool HasCycle(Node* head);
int DistanceFromLoop(Node* head);
int SumLinkedListReverse(Node* l1, Node* l2);
int SumLinkedList(Node* l1, Node* l2);
Node* FindMiddle(Node *head);
bool StackGrowsUp();
bool HeapGrowsUp();
bool IsPalindrom(Node* head);
void InsertDataInSortedCircularList(Node** root, int data);
// Using HashMap.
void RemoveDuplicates1(Node *node);
// Without any space.
void RemoveDuplicates2(Node *node);
// All smaller towards left and larger on right.
Node* PartitionList(Node *node, int data);
// Kth from the last.
Node* KthLastElem(Node *node, int k);
// Remove Node* by copying content of the next node.
void DeleteNode(Node* node);
// Checks loop.
bool DetectLoop(Node* node);
// Returns starting of loop.
Node* StartLoop(Node* node);

class QueueUsingTwoStacks {
public:
	void Enque(int a);
	int Deque();
private:
	stack<int> enq_;
	stack<int> deq_;
};

/*
 * What: HashMapWithLast
 *       Get(), Delete(), Put(), Has() and Last()
 * How: Using a list<> to locate the last referred element for Last.
 *      Search in the reverse order to keep the latest as last.
 */
template<typename K, typename V>
class HashMapWithLast {
	std::unordered_map<K, V> _map;
	std::list<K> _access;
public:
	void Put(const K& key, const V& value) {
		if (!Has(key)) {
			addNewAccess(key);
		}
		_map[key] = value;
	}
	V Get(const K& key) {
		updateAccess(key);
		return _map[key];
	}
	bool Has(const K& key) {
		return _map.count(key) > 0;
	}
	void Delete(const K& key) {
		deleteAccess(key);
		_map.erase(key);
	}
	K Last() {
		return _access.back();
	}
private:
	void updateAccess(const K& key) {
		if (Last() != key) {
			deleteAccess(key);
			addNewAccess(key);
		}
	}

	void deleteAccess(const K& key) {
		for (auto it = _access.rbegin(); it != _access.rend(); ++it) {
			if (*it == key) {
				it++;
				_access.erase((it).base());
				break;
			}
		}
	}
	void addNewAccess(const K& key) {
		_access.push_back(key);
	}
};

template<class T>
class Queue {
public:
	struct Node {
		T data_ { 0 };
		Node* next_ { nullptr };
		Node() :
				data_ { 0 } {
		}
		;
		Node(const T& data) :
				data_ { data } {
		}
	};
	void Push(const T& data) {
		Node* node = new Node(data);
		if (!head_) {
			head_ = back_ = node;
		} else {
			back_->next_ = node;
			back_ = back_->next_;
		}
	}
	void Pop() {
		if (!head_) {
			return;
		} else {
			//Just one node
			if (back_ == head_) {
				back_ = nullptr;
			}
			Node* node = head_;
			head_ = head_->next_;
			delete node;
		}
	}
	T Front() {
		return head_->data_;
	}
	bool Empty() {
		return !head_;
	}
private:
	Node* head_ { nullptr };
	Node* back_ { nullptr };
};

struct NodeWithWeight {
	int id_ { 0 };
	int parent_ { 0 };
	int weight_ { 0 };
	NodeWithWeight(int id, int parent, int weight) :
			id_ { id }, parent_ { parent }, weight_ { weight } {
	}
};
void PrintSubTreeWeights(const std::list<NodeWithWeight>& nodes);

template<typename T>
struct SmartPtr {
	T* ptr_;
	SmartPtr(T* ptr) :
			ptr_(ptr) {
	}
	~SmartPtr() {
		delete ptr_;
	}
	T* Get() {
		return ptr_;
	}
	T& operator->() {
		return *this;
	}
};


/*
 * What: Generic LinkedList Node class that does
 *       Push_front, Push_back, Remove, Remove_all
 */
template<typename T>
struct NodeGen {
	NodeGen *next { nullptr };
	T data;
	NodeGen(T dataPar) :
			data(dataPar) {
	}
};

/*
 * What: Generic LinkedList class that does
 *       Push_front, Push_back, Remove, Remove_all
 */
template<typename T>
class LinkedList {
private:
	NodeGen<T> *root_, *tail_;

public:

	/*
	 * What: Iterator to help LinkedList
	 *
	 */
	class Iterator {
	private:
		NodeGen<T> *p_;
	public:
		Iterator(const Iterator& itr) :
				p_(itr.p_) {
		}
		Iterator operator=(const Iterator& itr) {
			p_ = itr.p_;
			return *this;
		}
		Iterator(const NodeGen<T> *node) :
				p_(node) {
		}
		Iterator(NodeGen<T> *node) :
				p_(node) {
		}
		Iterator operator++() {
			Iterator result(p_);
			p_ = p_->next;
			return result;
		}
		Iterator operator++(int val) {
			p_ = p_->next;
			return *this;
		}

		T operator*() {
			return p_->data;
		}

		bool operator==(const Iterator& itr) {
			return itr.p_ == p_;
		}
		bool operator!=(const Iterator& itr) {
			return !operator==(itr);
		}
	};

	// Constructors.
	LinkedList() :
			root_ { nullptr }, tail_ { nullptr } {
	}
	LinkedList(LinkedList&& l) {
		root_ = move(l->root_);
		tail_ = move(l->tail_);
		delete l;
	}

	// Helper for For iterators.
	Iterator Begin() {
		Iterator itr(root_);
		return itr;
	}

	Iterator End() {
		NodeGen<T> *node = nullptr;
		Iterator itr(node);
		return itr;
	}

	// Insert at back.
	void Push_back(T data) {
		if (!root_) {
			root_ = new NodeGen<T>(data);
			tail_ = root_;
			return;
		}
		NodeGen<T> *node = new NodeGen<T>(data);
		tail_->next = node;
		tail_ = tail_->next;
	}

	// Insert at front.
	void Push_front(T data) {
		NodeGen<T> *node = new NodeGen<T>(data);
		node->next = root_;
		root_ = node;
		if (!tail_) {
			tail_ = root_;
		}
	}

	// Remove first elem with data.
	bool Remove(T data) {
		if (!root_) {
			return false;
		}
		if (root_->data == data) {
			NodeGen<T> *temp = root_;
			if (tail_ == root_) {
				root_ = root_->next;
				tail_ = root_;
			}
			delete temp;
			return true;
		}
		NodeGen<T> *prev = root_;
		NodeGen<T> *node = root_->next;
		while (node) {
			if (node->data == data) {
				prev->next = node->next;
				delete node;
				return true;
			}
			prev = node;
			node = node->next;
		}
		return false;
	}

	// Remove all elems with data.
	bool Remove_all(T data) {
		bool once = false;
		if (!root_) {
			return false;
		}
		NodeGen<T> *temp = root_;
		if (root_->data == data) {
			if (tail_ == root_) {
				root_ = root_->next;
				tail_ = root_;
			}
			delete temp;
			once = true;
		}
		NodeGen<T> *prev = root_;
		NodeGen<T> *node = root_->next;
		while (node) {
			if (node->data == data) {
				temp = node;
				prev->next = node->next;
				delete temp;
				once = true;
			}
			prev = node;
			node = node->next;
		}
		return once;
	}
};

}
#endif
