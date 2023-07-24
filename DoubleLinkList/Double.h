#pragma once
#include <iostream>
#include <fstream>
namespace DataStructure {

template <typename Type>
class Double
{	
private:
	class Node {
	public:
		Type value;
		Node* NextNode;
		Node* PrevNode;
		~Node() {};
		Node() {
		};
		Node(Type value, Node* NextNode = nullptr, Node* PrevNode = nullptr) {
			this->value = value;
			this->NextNode = NextNode;
			this->PrevNode = PrevNode;
		}
		
		friend std::ostream& operator<<(std::ostream& cout, Node* node) {

			cout << node->value;
			return cout;
		}
	};
		Node* new_node(Type _value, Node* _NextNode, Node* _PrevNode) {
			Node* temp = new Node();
			temp->value = _value;
			temp->NextNode = _NextNode;
			temp->PrevNode = _PrevNode;
			return temp;
		}
		Node* tail;
		Node* head;
		size_t length;

	public:
		/*friend std::ostream& operator<<(std::ostream& cout, LinkedList<Type>& list) {
			for (size_t i = 0; i < list.get_size(); i++)
			{
				cout << list.get(i)->value;
			}

			return cout;
		}*/
		size_t get_size() {
			return length;
		}
		~Double() {};
		Double (std::initializer_list<Type>array) {
			for (auto x = array.begin(); x != array.end(); x++)
			{
				push_back(*(x));
			}
		}
		Double() {
			head = new Node;
			head->NextNode = nullptr;
			head->PrevNode = nullptr;
			tail = head;
			length = 0;
		}
		Node* getUp(size_t index) {
			Node* temp = head;			
				if (index<0 || index>length) {
				throw std::out_of_range("Out of range");
				}
				for (size_t i = 0; i < index; i++) {
				temp = temp->NextNode;
				if (temp == nullptr)
				{
					return tail;
				}			
			}			
			return temp;
			
		}
		Node* getDown(size_t index) {
			Node* temp = tail;
			if (index<0 || index>length) {
				throw std::out_of_range("Out of range");
			}
			for (size_t i = length; i > index; i--) {
				temp = temp->PrevNode;
			}
			return temp;
		}
		Type& operator[](size_t index) {
			try {
				return getUp(index)->value;
			}
			catch (const std::out_of_range& e) {
				std::cout << e.what();
			}
		}
		Node* push_back(Type value) {
			
			if (!length) {
				length++;
				head = new_node(value, nullptr, nullptr);
				tail = head;
				return tail;
			}
			else {
				Node* temp= new Node(value);
				tail->NextNode = temp;
				tail = temp;
				tail->PrevNode = getDown(length-1);
				length++;
				return tail;
			}
		}
		Node* push_head(Type value) {
			Node* temp_node = new Node();
			if (head == nullptr) {
				temp_node = push_back(value);
			}
			else {
				temp_node = new_node(value, head, nullptr);
				head->PrevNode = temp_node;
				head = temp_node;
			}
			length++;
			return temp_node;
		}
		Node* pop() {
			if (!length) {
				return nullptr;
			}
			else {
				this->head = head->NextNode;
				head->PrevNode = nullptr;
				length--;
			}
			return head;
		}
		Node* pop_back() {
			Node* temp_node = new Node();
			if (head == nullptr) {
				return nullptr;
			}
			else if (head == tail) {
				head = new Node();
				tail = head;
				length--;
				return tail;
			}
			else {
				temp_node = tail;
				tail= getUp(length - 2);
				tail->NextNode = nullptr;
				length--;
				return temp_node;
			}
		}
		Node* remove(size_t index) {


			if (!length) {
				return nullptr;
			}
			else if (head == tail) {
				head = new Node();
				tail = head;
				length = 0;
			}
			else if (!index) {
				pop();
			}
			else if (index == length - 1) {
				pop_back();
			}
			else {
				Node* temp_node = getUp(index - 2);
				Node* help_node = getUp(index);
				temp_node->NextNode = help_node;
				help_node->PrevNode = temp_node;
				length--;
				return help_node;
			}
		}
		Node* insert(Type value, size_t index) {
			Node* ins_node = new Node(value); //добавл€ема€ €чейка
			Node* temp_node = getUp(index-1); // €чейка, чье место украли
			Node* help_node = getUp(index - 2); // €чейка, что помен€ет свою ссылку
			if (head == nullptr) {
				push_back(value);
			}
			else if (head == tail) {
				push_head(value);
			}
			else if (index == 0) {
				push_head(value);
			}
			else if (index == length - 1) {
				push_head(value);
			}
			else {
				ins_node->NextNode = temp_node;
				ins_node->PrevNode = help_node;
				help_node->NextNode = ins_node;
				temp_node->PrevNode=ins_node;
			}
			length++;
			return ins_node;
		}
		void print();
};

template<typename Type>
inline void Double<Type>::print()
{
	for (size_t i = 0; i < length; i++)
	{
		std::cout << getUp(i)->value<<" ";
	}
}

template<typename Type>
int smallPosition(Double <Type>&list, int q) {
	int start = q;
	for (int i = start; i < list.get_size(); i++)
	{
		if (list[i] < list[start]) {
			start = i;
		}
	}
	return start;
}
template<typename Type>
void Sort(Double<Type>&list) {
	
	Type temp;
	for (int i = 0; i < list.get_size(); i++)
	{
		int test = smallPosition(list, i);
		temp = list[i];
		list[i] = list[test];
		list[test] = temp;
	}
}
template<typename Type>
void SortBub(Double<Type>&list) {
	for (size_t i = 0; i < list.get_size(); i++)
	{
		for (size_t j = i+1; j < list.get_size(); j++)
		{
			if (list[i] > list[j]) {
				std::swap(list[i], list[j]);
			}
		}
	}
}
template<typename Type>
void save(Double<Type>& list) {
	std::ofstream write;
	write.open("text.txt");
	for (size_t i = 0; i < list.get_size(); i++)
	{
		if (write.is_open())
		{
			write << list[i] << " ";
		}
	}
	write << "\n";
	for (int i = list.get_size(); i >= 0; i--)
	{
		if (write.is_open())
		{
			write << list[i] << " ";
		}
	}
	write.close();
};
template<typename Type>
Type Summ(Double<Type> &list) {
	Type summ = 0;
	for (size_t i = 0; i < list.get_size(); i++)
	{
		summ += list[i];
	}
	return summ;
}
}
