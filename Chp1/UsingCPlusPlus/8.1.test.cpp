#include <iostream>

//define linkedlist
template<class T>
class Node {
public:
	Node<T> *next = nullptr;
	T data;
	Node(T d) {
		data = d;
	}
	void appendToTail(T d) {
		Node<T> *end = new Node<T>(d);
		Node<T> *n = this;
		while (n->next != nullptr) {
			n = n->next;
		}
		n->next = end;
	}
};

template<class T>
void removeRepeatedNode(Node<T> *head) {
	Node<T> *p = head;
	Node<T> *pre = head;
	Node<T> *q = head->next;

	while (p->next != nullptr) {
		while (q != nullptr) {
			if (p->data == q->data) {
				pre->next = q->next;
				q = q->next;
			}
			else {
				q = q->next;
				pre = pre->next;
			}		
		}

		p = p->next;
		q = p->next;
		pre = p;
	}
}

template<class T>
void printLinkedList(Node<T> *head) {
	while (head->next != nullptr) {
		std::cout << head->data << "-->";
		head = head->next;
	}
	std::cout << head->data << std::endl;
}

template<class T>
T findKNode(Node<T> *head, T k) {
	Node<T> *p = head;
	int len = 0;
	while (p != nullptr) {
		len++;
		p = p->next;
	}
	p = head;
	for (int i = 0; i < len - k; i++)
		p = p->next;

	return p->data;

}

template<class T>
void removeNode(Node<T> *head, T d) {

}

template<class T>
Node<T>* splitByX(Node<T> *head, T x) {
	Node<T> *first = head;
	Node<T> *end = nullptr;
	Node<T> *p = head;

	while (p->next != nullptr)
		p = p->next;
	end = p;

	p = head;

	if (p->next == nullptr)
		return first;
	if (p->next->next == nullptr)
		if (p->data > x && p->next->data < x) {
			first->next = nullptr;
			end->next = first;
			return end;
		}
		else
			return first;

	Node<T> *pre = p;
	p = p->next;
	while (p != nullptr) {
		if (p->data >= x) {
			//·Åµ½Î²²¿
			pre->next = p->next;
			p->next = nullptr;
			end->next = p;
			end = p;

		}
		p = p->next;
		pre = pre->next;
	}
	return first;
}

template<class T>
void add(Node<T> *n1, Node<T> *n2, Node<T> result) {

}


int main1(void) {
	Node<int> *head = new Node<int>(1);
	head->appendToTail(2);
	head->appendToTail(6);
	head->appendToTail(1);
	head->appendToTail(3);
	head->appendToTail(7);
	head->appendToTail(4);

	printLinkedList(head);

	splitByX(head, 3);

	printLinkedList(head);

	return 0;
}