#pragma once
#include <iostream>
#include <stdexcept>
#include <limits>
#include <vector>

/*
* @brief ��������� ��� ���������� ������ List, � ������� �������� ���������� �� ��������, � ����� ������ �� ���������� � ��������� ��������.
*/
template <typename T>
struct Element {
	T data;
	Element* previous;
	Element* next;
};

/*
* @brief ����� List. �������������� �� ���� ���������� ������������ ������.
*/
template <typename T>
class List {
private:
	Element<T>* head;
	Element<T>* tail;
	size_t size;
public:

	/*
	* @breif ����������� �� ���������.
	*/
	List();

	/*
	* @brief �����, ����������� �������� ������ � ���� �������.
	* @return ������, � ���� ������� T.
	*/
	std::vector<T> getListAsVector() const;

	/*
	* @brief �����, ����������� �������� ������ ������.
	* @return ������ ������.
	*/
	size_t getSize() const;

	/*
	* @brief �����, ����������� �������� ������� � ����� ������.
	* @param newData - ���������� � ����� ��������
	*/
	void pushBack(T newData);

	/*
	* @brief �����, ����������� �������� ������� � ������ ������.
	* @param newData - ���������� � ����� ��������.
	*/
	void pushFront(T newData);

	/*
	* @brief �����, ����������� �������� ���������� � ������ �������� ������.
	* @return ���������� � ������ ��������.
	*/
	T getFront() const;

	/*
	* @brief �����, ����������� �������� ���������� � ��������� �������� ������.
	* @return ���������� � ��������� ��������.
	*/
	T getBack() const;

	/*
	* @brief �����, ��������� ������ ������� ������.
	*/
	void popFront();

	/*
	* @brief �����, ��������� ��������� ������� ������.
	*/
	void popBack();

	/*
	* @brief �����, ��������� ������� ������ �� �����.
	* @param position - ���� (������� �������� � ������).
	*/
	void deleteELement(size_t position);

	/*
	* @brief �����, ����������� �������� ������� � ������.
	* @param data - ���������� �� �������� (��� ������).
	* @param position - �������, �� ������� ����� ������� ���������.
	*/
	void insertElement(T data, size_t position);

	/*
	* @brief �����, ����������� �������� ������ �� �������� ������.
	* @param position - ������� �������� � ������.
	* @return ���������� �� �������� - ��� ������.
	*/
	T getElement(size_t position) const;

	/*
	* @brief �����, ����������� �������� ������� �������� 2 ��������� ������.
	* @param positionOne - ������� ������� ��������.
	* @param positionTwo - ������� ������� ��������.
	*/
	void swap(size_t positionOne, size_t positionTwo);

	/*
	* @brief �����, ��������� ������������ ������� � ������.
	* @return ������������ ������� ������.
	*/
	T getMax() const;

	/*
	* @brief �����, ��������� ����������� ������� � ������.
	* @return ����������� ������� ������.
	*/
	T getMin() const;

	/*
	* @brief �����, ��������� ��� �������� ������.
	*/
	void deleteAll();

	/*
	* @brief ����������� �����������.
	*/
	List(const List& other);

	/*
	* @brief �������� �����������.
	*/
	List& operator = (const List& other);

	/*
	* @brief ����������� �����������.
	*/
	List(List&& other) noexcept;

	/*
	* @brief �������� �����������
	*/
	List& operator = (List&& other) noexcept;

	/*
	* @brief ����������
	*/
	~List();
};


template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {};

template <typename T>
List<T>::List(const List& other) : List()
{
	Element<T>* temp = other.head;
	while (temp != nullptr)
	{
		this->pushBack(temp->data);
		temp = temp->next;
	}
	this->size = other.size;
}

template <typename T>
List<T>& List<T>::operator = (const List& other) {
	if (this == &other)
		return *this;
	List<T> copy(other);
	std::swap(this->tail, copy.tail);
	std::swap(this->head, copy.head);
	std::swap(this->size, copy.size);

	return *this;
}

template <typename T>
size_t List<T>::getSize() const{
	return this->size;
}

template <typename T>
std::vector<T> List<T>::getListAsVector() const {
	std::vector<T> out;
	auto temp = this->head;
	while (temp != nullptr) {
		out.push_back(temp->data);
		temp = temp->next;
	}
	return out;
}

template <typename T>
void List<T>::pushBack(T newData) {
	Element<T>* temp = new Element<T>();
	temp->data = newData;
	temp->next = nullptr;
	if (this->getSize() == 0) {
		temp->previous = nullptr;
		this->head = temp;
		this->tail = temp;
	}
	else {
		temp->previous = this->tail;
		tail->next = temp;
		this->tail = temp;
	}
	++this->size;
}

template <typename T>
void List<T>::pushFront(T newData) {
	Element<T>* temp = new Element<T>();
	temp->data = newData;
	temp->previous = nullptr;
	if (this->getSize() == 0) {
		temp->next = nullptr;
		this->head = temp;
		this->tail = temp;
	}
	else {
		temp->next = this->head;
		head->previous = temp;
		this->head = temp;
	}
	++this->size;
}

template <typename T>
T List<T>::getFront() const {
	return this->head->data;
}

template <typename T>
T List<T>::getBack() const {
	return this->tail->data;
}

template <typename T>
void List<T>::popBack() {
	if (this->getSize() == 0)
		throw std::logic_error("������ ������� �������� � ������ �����");
	if (this->getSize() == 1) {
		delete this->tail;
		this->head = nullptr;
		this->tail = nullptr;
		--this->size;
		return;
	}
	else if (this->getSize() == 2) {
		delete this->tail;
		this->head->next = nullptr;
		this->tail = this->head;
		--this->size;
		return;
	}
	auto temp = this->tail;
	this->tail = this->tail->previous ;
	delete temp;
	--this->size;
}

template <typename T>
void List<T>::popFront() {
	if (this->getSize() == 0)
		throw std::logic_error("������ ������� �������� � ������ �����");
	if (this->getSize() == 1) {
		delete this->head;
		this->head = nullptr;
		this->tail = nullptr;
		--this->size;
		return;
	}
	else if (this->getSize() == 2) {
		delete this->head;
		this->tail->previous = nullptr;
		this->head = this->tail;
		--this->size;
		return;
	}
	auto temp = this->head;
	this->head = this->head->next;
	delete temp;
	--this->size;
}

template <typename T>
void List<T>::deleteELement(size_t position) {
	if (position >= this->getSize())
		throw std::out_of_range("������� ������ ������� ������");
	if (position == 0) {
		this->popFront();
		return;
	}
	else if (position == this->getSize() - 1) {
		this->popBack();
		return;
	}
	auto temp = this->head;
	for (size_t i = 0; i < position; i++)
	{
		temp = temp->next;
	}
	temp->previous->next = temp->next;
	temp->next->previous = temp->previous;
	delete temp;
	--this->size;
}

template <typename T>
void List<T>::insertElement(T data, size_t position) {
	if (position > this->getSize())
		throw std::out_of_range("������� ������ ������� ������");
	if (position == 0) {
		this->pushFront(data);
		return;
	}
	else if (position == this->getSize()) {
		this->pushBack(data);
		return;
	}
	auto insert = this->head;
	for (size_t i = 0; i < position; i++)
	{
		insert = insert->next;
	}
	Element<T>* temp = new Element<T>();
	temp->data = data;
	if (insert->previous != nullptr && this->getSize() != 1)
		insert->previous->next = temp;
	temp->next = insert;
	temp->previous = insert->previous;
	insert->previous = temp;

	++this->size;
}

template <typename T>
T List<T>::getElement(size_t position) const{
	if (position >= this->getSize())
		throw std::out_of_range("������� ������ ������� ������");
	auto get = this->head;
	for (size_t i = 0; i < position; i++)
	{
		get = get->next;
	}
	return get->data;
}

template <typename T>
void List<T>::swap(size_t positionOne, size_t positionTwo) {
	if (positionOne > this->getSize() || positionTwo > this->getSize())
		throw std::out_of_range("������� ������ ������� ������");
	auto tempOne = this->head;
	auto tempTwo = this->head;
	if (positionOne >= positionTwo) {
		for (size_t i = 0; i < positionTwo; i++)
		{
			tempOne = tempOne->next;
			tempTwo = tempTwo->next;
		}
		for (size_t i = positionTwo; i < positionOne; i++)
		{
			tempOne = tempOne->next;
		}
	}
	else {
		for (size_t i = 0; i < positionOne; i++)
		{
			tempOne = tempOne->next;
			tempTwo = tempTwo->next;
		}
		for (size_t i = positionOne; i < positionTwo; i++)
		{
			tempTwo = tempTwo->next;
		}
	}
	std::swap(tempOne->data, tempTwo->data);
}

template <typename T>
T List<T>::getMax() const {
	T max = std::numeric_limits<T>::min();
	auto maxPointer = this->head;
	for (size_t i = 0; i < this->getSize() - 1; i++)
	{
		if (max < maxPointer->data)
			max = maxPointer->data;
		maxPointer = maxPointer->next;
	}
	return max;
}

template <typename T>
T List<T>::getMin() const {
	T min = std::numeric_limits<T>::max();
	auto minPointer = this->head;
	for (size_t i = 0; i < this->getSize() - 1; i++)
	{
		if (min > minPointer->data)
			min = minPointer->data;
		minPointer = minPointer->next;
	}
	return min;
}

template <typename T>
void List<T>::deleteAll() {
	while (this->getSize() != 0)
		this->popBack();
}

template <typename T>
List<T>::~List() {
	this->deleteAll();
}


template <typename T>
List<T>::List(List&& other) noexcept : head(other->head), tail(other->tail), size(other->size) {
	other.count = 0;
	other.head = nullptr;
	other.tail = nullptr;
}

template <typename T>
List<T>& List<T>::operator = (List&& other) noexcept {
	if (this == *other)
		return *this;
	std::swap(this->tail, other.tail);
	std::swap(this->head, other.head);
	std::swap(this->size, other.size);
	return *this;
}


template <typename T>
std::ostream& operator << (std::ostream& os, const List<T>& list) {
	std::vector<T> out = list.getListAsVector();
	for (size_t i = 0; i < out.size(); i++)
	{
		os << out[i] << " ";
	}
	return os;
}