#include"linkedlist.h"

#include<cassert>
#include<iostream>
#include <cstdlib>
#include <ctime>

namespace linkedlist {

using namespace std;

void Test_Insert() {
	cout << "Started testing Test_Insert()" << endl;
	Node* node = nullptr;
	Insert(&node, 1);
	Insert(&node, 2);
	assert(node->data_ == 2);
	assert(node->next_->data_ == 1);
	cout << "Done testing Test_Insert()" << endl;
}

void Test_Delete() {
	cout << "Started testing Test_Delete()" << endl;
	Node* node = nullptr;
	Insert(&node, 1);
	cout << "Inserting 1" << endl;
	Print(&node);
	Insert(&node, 2);
	cout << "Inserting 2" << endl;
	Print(&node);
	Delete(&node, 1);
	cout << "Deleting 1" << endl;
	Print(&node);
	cout << "Done deleting " << 1 << endl;
	Delete(&node, 2);
	cout << "Deleting 2" << endl;
	Print(&node);
	assert(node == nullptr);
	cout << "Done deleting " << 2 << endl;
	cout << "Done testing Test_Delete()" << endl;
}

void Test_Clear() {
	cout << "Started testing Test_Clear()" << endl;
	Node* node = nullptr;
	Insert(&node, 1);
	cout << "Inserting 1" << endl;
	Print(&node);
	Insert(&node, 2);
	cout << "Inserting 2" << endl;
	Print(&node);
	cout << "Clearing now" << endl;
	Clear(&node);
	Print(&node);
	assert(node == nullptr);
	cout << "Done testing Test_Clear()" << endl;
}

void Test_Split() {
	cout << "Started testing Test_Split()" << endl;
	Node* node = nullptr;
	Insert(&node, 1);
	Insert(&node, 5);
	Insert(&node, 2);
	Insert(&node, 4);
	Insert(&node, 3);
	cout << "Printing current nodes" << endl;
	Print(&node);
	Node* lNode = nullptr;
	Node* gNode = nullptr;
	cout << "Splitting on 3 using Test_Split()" << endl;
	Split(node, 3, &lNode, &gNode);
	cout << "Printing lesser nodes" << endl;
	Print(&lNode);
	cout << "Printing greater nodes" << endl;
	Print(&gNode);
	cout << "Done testing Test_Split()" << endl;
}

void Test_HasCycle() {
	cout << "Started testing Test_HasCycle()" << endl;
	Node* node = nullptr;
	Insert(&node, 1);
	Node* node2 = node;
	Insert(&node, 2);
	Insert(&node, 3);
	Insert(&node, 4);
	Insert(&node, 5);
	Insert(&node, 6);
	node2->next_ = node;
	assert(HasCycle(node) == true);
	cout << "Cycle found as expected" << endl;
	node2->next_ = nullptr;
	assert(HasCycle(node) == false);
	cout << "Cycle not found as expected" << endl;
	Print(&node);
	cout << "Done testing Test_HasLoop()" << endl;
}

void Test_FindMiddle() {
	cout << "Started testing Test_FindMiddle()" << endl;
	Node* node = nullptr;
	Insert(&node, 1);
	Node* node2 = node;
	Insert(&node, 2);
	Insert(&node, 3);
	Insert(&node, 4);
	Insert(&node, 5);
	Insert(&node, 6);
	Insert(&node, 7);
	Insert(&node, 8);
	Insert(&node, 9);
	node2->next_ = node;
	assert(FindMiddle(node) == nullptr);
	cout << "With a loop it returned nullptr" << endl;
	node2->next_ = nullptr;
	Print(&node);
	Node* center = FindMiddle(node);
	cout << "Middle is node with data " << center->data_ << endl;
	cout << "Done testing Test_FindMiddle()" << endl;
}

void Test_Queue() {
	cout << "Started testing Test_Queue()" << endl;
	Queue<int> q;
	for (int i = 0; i < 100; i += 10) {
		q.Push(i);
	}
	cout << "Is Queue empty : " << q.Empty() << endl;
	for (int i = 0; i < 100; i += 10) {
		cout << "Popping : " << q.Front() << endl;
		q.Pop();
	}
	cout << "Is Queue empty : " << q.Empty() << endl;
	cout << "Done testing Test_Queue()" << endl;
}

void Test_StackGrowsUp() {
	cout << "Started testing Test_StackGrowsUp()" << endl;
	if (StackGrowsUp()) {
		cout << "Stack grows up" << endl;
	} else {
		cout << "Stack grows down" << endl;
	}
	cout << "Done testing Test_StackGrowsUp()" << endl;
}

void Test_HeapGrowsUp() {
	cout << "Started testing Test_HeapGrowsUp()" << endl;
	if (HeapGrowsUp()) {
		cout << "Heap grows up" << endl;
	} else {
		cout << "Heap grows down" << endl;
	}
	cout << "Done testing Test_HeapGrowsUp()" << endl;
}

void Test_DistanceFromLoop() {
	cout << "Started testing Test_DistanceFromLoop()" << endl;
	assert(DistanceFromLoop(nullptr) == 0);
	Node* head = new Node(1);
	assert(DistanceFromLoop(head) == 0);
	Node* node = head;
	for (int i = 2; i <= 10; i++) {
		node->next_ = new Node(i);
		node = node->next_;
	}
	// Loop start at 3
	node->next_ = head->next_->next_;
	cout << "Distance from head should be 2 : " << DistanceFromLoop(head)
			<< endl;
	assert(DistanceFromLoop(head) == 2);
	cout << "Done testing Test_DistanceFromLoop()" << endl;
}

void Test_SumLinkedListReverse() {
	cout << "Started testing Test_SumLinkedListReverse()" << endl;
	Node* l1 = new Node(3);
	l1->next_ = new Node(2);
	l1->next_->next_ = new Node(1);
	Node* l2 = new Node(6);
	l2->next_ = new Node(5);
	l2->next_->next_ = new Node(4);
	cout << "SumLinkedListReverse() should be 579 : "
			<< SumLinkedListReverse(l1, l2) << endl;
	assert(SumLinkedListReverse(l1, l2) == 579);
	cout << "Done testing Test_SumLinkedListReverse()" << endl;
}

void Test_SumLinkedList() {
	cout << "Started testing Test_SumLinkedList()" << endl;
	Node* l1 = new Node(1);
	l1->next_ = new Node(2);
	l1->next_->next_ = new Node(3);
	Node* l2 = new Node(4);
	l2->next_ = new Node(5);
	l2->next_->next_ = new Node(6);
	cout << "SumLinkedList() should be 579 : " << SumLinkedList(l1, l2) << endl;
	//assert(SumLinkedList(l1, l2) == 579);
	cout << "Done testing Test_SumLinkedList()" << endl;
}

void Test_Reverse() {
	cout << "Started testing Test_Reverse()" << endl;
	Node* head = new Node(1);
	Node* node = head;
	for (int i = 2; i <= 10; ++i) {
		node->next_ = new Node(i);
		node = node->next_;
	}
	Print(&head);
	cout << endl << "After reversing" << endl;
	Reverse(&head);
	Print(&head);
	cout << "Done testing Test_Reverse()" << endl;
}

void Test_IsPalindrom() {
	cout << "Start testing Test_IsPalindrom()" << endl;
	Node* head = new Node(1);
	Node* node = head;
	for (int i = 2; i <= 5; ++i) {
		node->next_ = new Node(i);
		node = node->next_;
	}
	for (int i = 4; i >= 1; --i) {
		node->next_ = new Node(i);
		node = node->next_;
	}
	Print(&head);
	cout << "Is Palindrome ? : " << IsPalindrom(head) << endl;
	node->next_ = new Node(5);
	node = node->next_;
	Print(&head);
	cout << "Is Palindrome ? : " << IsPalindrom(head) << endl;
	cout << "Done testing Test_IsPalindrom()" << endl;
}

void Test_QueueUsingTwoStacks() {
	cout << "Started testing Test_QueueUsingTwoStacks()" << endl;
	cout << "Enqueing 1, 2, 3, 4, 5" << endl;
	QueueUsingTwoStacks q;
	q.Enque(1);
	q.Enque(2);
	q.Enque(3);
	q.Enque(4);
	q.Enque(5);
	cout << "Dequeue 1, 2, 3, 4 " << endl;
	cout << "Dequeing " << q.Deque() << endl;
	cout << "Dequeing " << q.Deque() << endl;
	cout << "Dequeing " << q.Deque() << endl;
	cout << "Dequeing " << q.Deque() << endl;
	cout << "Dequeing " << q.Deque() << endl;
	cout << "Enqueing 6, 7" << endl;
	q.Enque(6);
	q.Enque(7);
	cout << "Dequeue 5, 6, 7" << endl;
	cout << "Dequeing " << q.Deque() << endl;
	cout << "Dequeing " << q.Deque() << endl;
	cout << "Done testing Test_QueueUsingTwoStacks()" << endl;
}

void Test_InsertDataInSortedCircularList() {
	cout << "Start testing Test_InsertDataInSortedCircularList()" << endl;
	Node** root = new (Node*);
	*root = nullptr;
	srand(time(NULL));
	int length = 100;
	for (int i = 0; i < 100; ++i) {
		InsertDataInSortedCircularList(root, rand() % length);
	}
	Node* node = *root;
	for (int i = 0; i < length; ++i) {
		cout << node->data_ << ", ";
		node = node->next_;
	}
	cout << endl;
	cout << "Done testing Test_InsertDataInSortedCircularList()" << endl;
}

void Test_PrintSubTreeWeights() {
	cout << "Start testing Test_PrintSubTreeWeights()" << endl;
	list<NodeWithWeight> nodes;
	nodes.push_back(NodeWithWeight(0, 0, 0));
	for (int i = 0; i < 10; ++i) {
		nodes.push_back(NodeWithWeight(i + 1, i, i + 1));
	}
	PrintSubTreeWeights(nodes);
	cout << "Done testing Test_PrintSubTreeWeights()" << endl;
}

void Test_HashMapWithLast() {
	cout << "Start testing Test_HashMapWithLast()" << endl;
	HashMapWithLast<int, int> mapLast;
	for (int i = 1; i < 10; ++i) {
		mapLast.Put(i, i + 5);
	}
	mapLast.Get(5);
	mapLast.Get(6);
	for (int i = 10; i > 0; --i) {
		mapLast.Delete(i);
		cout << mapLast.Last() << " ";
	}
	cout << "Should be 6 6 6 6 5 4 3 2 1 0 " << endl;
	cout << "Done testing Test_HashMapWithLast()" << endl;
}

void Test_SmartPtr() {
	cout << "Start testing Test_SmartPtr()" << endl;
	struct Node {
		~Node() {
			cout << "Destruct" << endl;
		}
	};
	{
		SmartPtr<Node> n(new Node);
	}
	cout << "Outside" << endl;
	cout << "Done testing Test_SmartPtr()" << endl;
}

void Test_RemoveDuplicates() {
	cout << "Start testing Test_RemoveDuplicates()" << endl;
	Node *node = new Node(1);
	node->next_ = new Node(2);
	node->next_->next_ = new Node(1);
	RemoveDuplicates1(node);
	assert(node->next_->next_ == nullptr);
	node->next_->next_ = new Node(1);
	RemoveDuplicates2(node);
	assert(node->next_->next_ == nullptr);
	cout << "Done testing Test_RemoveDuplicates()" << endl;
}

void Test_PartitionList() {
	cout << "Start testing Test_PartitionList()" << endl;
	Node *node = new Node(1);
	node->next_ = new Node(8);
	node->next_->next_ = new Node(3);
	node->next_->next_->next_ = new Node(6);
	Node* out = PartitionList(node, 5);
	assert(out->data_ = 1);
	assert(out->next_->data_ = 3);
	assert(out->next_->next_->data_ = 8);
	assert(out->next_->next_->next_->data_ = 6);
	cout << "Done testing Test_PartitionList()" << endl;
}

void Test_KthLastElem() {
	cout << "Start testing Test_KthLastElem()" << endl;
	Node *node = new Node(1);
	node->next_ = new Node(2);
	node->next_->next_ = new Node(3);
	Node *out = KthLastElem(node, 2);
	assert(out->data_ == 2);
	cout << "Done testing Test_KthLastElem()" << endl;
}

void Test_DeleteNode() {
	cout << "Start testing Test_DeleteNode()" << endl;
	Node *node = new Node(1);
	node->next_ = new Node(2);
	node->next_->next_ = new Node(3);
	DeleteNode(node->next_);
	assert(node->next_->data_ == 3);
	cout << "Done testing Test_DeleteNode()" << endl;
}

void Test_DetectLoop() {
	cout << "Start testing Test_DetectLoop()" << endl;
	//1->2->3->4->|
	//    |-<-<-<-<-
	Node *node = new Node(1);
	node->next_ = new Node(2);
	node->next_->next_ = new Node(3);
	node->next_->next_->next_ = new Node(4);
	node->next_->next_->next_ = node->next_;
	assert(DetectLoop(node));
	cout << "Done testing Test_DetectLoop()" << endl;
}

void Test_StartLoop() {
	cout << "Start testing Test_StartLoop()" << endl;
	//1->2->3->4->|
	//    |-<-<-<-<-
	Node *node = new Node(1);
	node->next_ = new Node(2);
	node->next_->next_ = new Node(3);
	node->next_->next_->next_ = new Node(4);
	node->next_->next_->next_ = node->next_;
	assert(StartLoop(node) == node->next_);
	cout << "Done testing Test_StartLoop()" << endl;
}

void Test_LinkedListGeneric() {
	cout << "Start testing Test_LinkedListGeneric()" << endl;
	LinkedList<int> l;
	l.Push_back(5);
	l.Push_back(6);
	l.Push_back(7);
	l.Remove(6);
	for (LinkedList<int>::Iterator i = l.Begin(); i != l.End(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	l.Push_front(2);
	l.Push_back(8);
	l.Push_back(9);
	l.Push_back(8);
	l.Remove_all(8);
	for (LinkedList<int>::Iterator i = l.Begin(); i != l.End(); i++) {
		cout << *i << " ";
	}
	cout << endl;
	cout<<"Done testing Test_LinkedListGeneric()"<<endl;
}

void Test_LinkedLists() {
#ifdef TEST_DONE
Test_Insert();
Test_Delete();
Test_Clear();
Test_Split();
Test_HasCycle();
Test_FindMiddle();
Test_Queue();
Test_StackGrowsUp();
Test_HeapGrowsUp();
Test_DistanceFromLoop();
Test_SumLinkedListReverse();
Test_Reverse();
Test_SumLinkedList();
Test_IsPalindrom();
Test_QueueUsingTwoStacks();
Test_InsertDataInSortedCircularList();
Test_PrintSubTreeWeights();
#endif
Test_HashMapWithLast();
Test_SmartPtr();
Test_RemoveDuplicates();
Test_PartitionList();
Test_KthLastElem();
Test_DeleteNode();
Test_DetectLoop();
Test_StartLoop();
Test_LinkedListGeneric();
}

}
