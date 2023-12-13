#include "pch.h"
#include "../List/List.h"
#include <string>

using namespace std;


class ListTest : public testing::Test {
protected:
	List<int> l1;
	List<string> l2;
	std::vector<int> v1 = { 1, 5 };
	std::vector<string> v2 = { "qwe" };
	void SetUp() override {
		l1.pushBack(1);
		l1.pushBack(5);
		l2.pushFront("qwe");
	}
};

TEST_F(ListTest, CopyConstructorIntWorks) {
	List<int> l3 = List<int>(l1);
	auto v = l1.getListAsVector();
	for (size_t i = 0; i < v1.size(); i++)
	{
		EXPECT_EQ(v[i], v1[i]);
	}
}

TEST_F(ListTest, CopyConstructorStringWorks) {
	List <string> l3 = List<string>(l2);
	auto v = l3.getListAsVector();
	for (size_t i = 0; i < v2.size(); i++)
	{
		EXPECT_EQ(v[i], v2[i]);
	}
}

TEST_F(ListTest, PushBackIntWorks) {
	l1.pushBack(10);
	v1.push_back(10);
	auto v = l1.getListAsVector();
	for (size_t i = 0; i < v1.size(); i++)
	{
		EXPECT_EQ(v[i], v1[i]);
	}
}

TEST_F(ListTest, PushBackStringWorks) {
	l2.pushBack("rty");
	v2.push_back("rty");
	auto v = l2.getListAsVector();
	for (size_t i = 0; i < v2.size(); i++)
	{
		EXPECT_EQ(v[i], v2[i]);
	}
}

TEST_F(ListTest, PushFrontIntWorks) {
	l1.pushFront(10);
	std::vector<int> v3 = { 10, 1, 5 };
	auto v = l1.getListAsVector();
	for (size_t i = 0; i < v3.size(); i++)
	{
		EXPECT_EQ(v[i], v3[i]);
	}
}

TEST_F(ListTest, PushFrontStringWorks) {
	l2.pushFront("rty");
	std::vector<string> v3 = { "rty", "qwe" };
	auto v = l2.getListAsVector();
	for (size_t i = 0; i < v3.size(); i++)
	{
		EXPECT_EQ(v[i], v3[i]);
	}
}

TEST_F(ListTest, PopFrontThrowsLogicError) {
	List <int> l3;
	EXPECT_THROW(l3.popFront(), logic_error);
}

TEST_F(ListTest, PopFrontWorks ) {
	l1.popFront();
	EXPECT_EQ(l1.getSize(), 1);
	EXPECT_EQ(l1.getListAsVector()[0], 5);

	l2.popFront();
	EXPECT_EQ(l2.getSize(), 0);
}

TEST_F(ListTest, PopBackThrowsLogicError) {
	List <int> l3;
	EXPECT_THROW(l3.popBack(), logic_error);
}

TEST_F(ListTest, PopBackWorks) {
	l1.popBack();
	EXPECT_EQ(l1.getSize(), 1);
	EXPECT_EQ(l1.getListAsVector()[0], 1);

	l2.popBack();
	EXPECT_EQ(l2.getSize(), 0);
}

TEST_F(ListTest, DeleteElementThrowsOutOfRange) {
	EXPECT_THROW(l1.deleteELement(4), out_of_range);
}

TEST_F(ListTest, DeleteElementWorks) {
	l1.pushFront(10);
	l1.deleteELement(1);
	std::vector<int> v3 = { 10, 5 };
	auto v = l1.getListAsVector();
	for (size_t i = 0; i < v3.size(); i++)
	{
		EXPECT_EQ(v[i], v3[i]);
	}
}

TEST_F(ListTest, InsertElementThrowsOutOfRange) {
	EXPECT_THROW(l1.insertElement(14, 4), out_of_range);
}

TEST_F(ListTest, InserElementIntWorks) {
	l1.insertElement(3, 1);
	auto v = l1.getListAsVector();
	std::vector<int> v3 = { 1, 3, 5 };
	for (size_t i = 0; i < v3.size(); i++)
	{
		EXPECT_EQ(v[i], v3[i]);
	}
}

TEST_F(ListTest, InsertElementStringWorks) {
	l2.pushBack("rty");
	l2.insertElement("---", 1);
	std::vector<string> v3 = { "qwe", "---", "rty" };
	auto v = l2.getListAsVector();
	for (size_t i = 0; i < v3.size(); i++)
	{
		EXPECT_EQ(v[i], v3[i]);
	}
}

TEST_F(ListTest, GetFrontIntWorks) {
	EXPECT_EQ(l1.getFront(), 1);
}

TEST_F(ListTest, GetFrontStringWorks) {
	EXPECT_EQ(l2.getFront(), "qwe");
}

TEST_F(ListTest, GetBackIntWorks) {
	EXPECT_EQ(l1.getBack(), 5);
}


TEST_F(ListTest, GetBackStringWorks) {
	EXPECT_EQ(l2.getBack(), "qwe");
}

TEST_F(ListTest, GetElementThrowsOutOfRange) {
	EXPECT_THROW(l1.deleteELement(4), out_of_range);
}

TEST_F(ListTest, GetElementIntWorks) {
	l1.pushBack(10);
	l1.pushBack(15);
	EXPECT_EQ(l1.getElement(2), 10);
	EXPECT_EQ(l1.getElement(3), 15);
	EXPECT_EQ(l1.getElement(0), 1);
}

TEST_F(ListTest, GetElementStringWorks) {
	l2.pushBack("---");
	l2.pushBack("rty");
	EXPECT_EQ(l2.getElement(1), "---");
}

TEST_F(ListTest, SwapThrowsOutOfRange) {
	EXPECT_THROW(l1.swap(2, 5), out_of_range);
}

TEST_F(ListTest, SwapIntWorks) {
	l1.pushBack(10);
	l1.pushBack(20);
	l1.swap(0, 3);
	l1.swap(1, 2);
	auto v = l1.getListAsVector();
	std::vector<int> v3 = { 20, 10, 5, 1 };
	for (size_t i = 0; i < v3.size(); i++)
	{
		EXPECT_EQ(v[i], v3[i]);
	}
}

TEST_F(ListTest, SwapStringWorks) {
	l2.pushBack("rty");
	l2.swap(0, 1);
	auto v = l2.getListAsVector();
	std::vector<string> v3 = { "rty","qwe" };
	for (size_t i = 0; i < v3.size(); i++)
	{
		EXPECT_EQ(v[i], v3[i]);
	}
}

TEST_F(ListTest, GetMaxIntWorks) {
	l1.pushBack(10);
	l1.pushBack(7);
	EXPECT_EQ(l1.getMax(), 10);
}

TEST_F(ListTest, GetMinIntWorks) {
	l1.pushBack(-3);
	l1.pushBack(2);
	EXPECT_EQ(l1.getMin(), -3);
}

TEST_F(ListTest, DeleteAllWorks) {
	EXPECT_NO_FATAL_FAILURE(l1.deleteAll());
	EXPECT_EQ(l1.getSize(), 0);
}

