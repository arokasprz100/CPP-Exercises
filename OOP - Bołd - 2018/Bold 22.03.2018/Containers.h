#ifndef Containers_h
#define Containers_h

#include <string>
#include <iostream>

namespace oop 
{

	class Object
	{
	public:
		Object(std::string name = "oop::Object"):
			m_name(name) {}

		std::string name() const { return m_name; }

		virtual ~Object () { std::cout<<"oop::~Object"<<std::endl; }

	protected:
		std::string m_name; 
	};



	class Container : public Object 
	{
	public:
		void size() const {}

		void empty() const {}

		void insert(const Container* inserted) {}

		virtual ~Container() { std::cout<<"oop::~Container"<<std::endl; }
		
	protected:
		Container (std::string name = "oop::Container"):
			Object(name) {}
	};


	class SequenceContainer : public Container
	{
	public:

		virtual void push_front(const Object* inserted) = 0;

		virtual void push_back(const Object* inserted) = 0;

		virtual ~SequenceContainer() { std::cout<<"oop::~SequenceContainer"<<std::endl; }

	protected:
		SequenceContainer(std::string name = "oop::SequenceContainer") :
			Container(name) {}
	};


	class List : public SequenceContainer
	{
	public:
		List ():
			SequenceContainer("oop::List") {}

		virtual void push_front(const Object* inserted) {};
		virtual void push_back(const Object* inserted) {};

		~List () {std::cout<<"oop::~List"<<std::endl;}
	};


	class Vector : public SequenceContainer
	{
	public:
		Vector ():
			SequenceContainer("oop::Vector") {}

		virtual void push_front(const Object* inserted) {};
		virtual void push_back(const Object* inserted) {};

		~Vector () {std::cout<<"oop::~Vector"<<std::endl;}
	};


	class TreeContainer : public Container
	{
	protected:
		TreeContainer(std::string name = "oop::TreeContainer" ):
			Container(name){}
	};


	class SortedTreeContainer : public TreeContainer
	{
	protected:
		SortedTreeContainer(std::string name = "oop::SortedTreeContainer" ):
			TreeContainer(name) {}
	public:
		virtual ~SortedTreeContainer() {std::cout<<"oop::~SortedTreeContainer"<<std::endl;}

	};


	class SortedTree : public SortedTreeContainer
	{
	public:
		SortedTree(std::string name = "oop::SortedTree" ):
			SortedTreeContainer(name) {}

		~SortedTree() {std::cout<<"oop::~SortedTree"<<std::endl;}

	};


	class SortedMultiTree : public SortedTreeContainer
	{
	public:
		SortedMultiTree(std::string name = "oop::SortedMultiTree"):
			SortedTreeContainer(name){}

		~SortedMultiTree() {std::cout<<"oop::~SortedMultiTree"<<std::endl;}

	};


	class HashTreeContainer : public TreeContainer
	{
	protected:
		HashTreeContainer(std::string name = "oop::HashTreeContainer"):
			TreeContainer(name){}
	public:
		virtual ~HashTreeContainer() {std::cout<<"oop::~HashTreeContainer"<<std::endl;}
	};


	class HashTree : public HashTreeContainer
	{
	public:
		HashTree(std::string name = "oop::HashTree" ):
			HashTreeContainer(name) {}

		~HashTree() {std::cout<<"oop::~HashTree"<<std::endl; }

	};


	class HashMultiTree : public HashTreeContainer
	{
	public:
		HashMultiTree(std::string name = "oop::HashMultiTree" ):
			HashTreeContainer(name) {}

		~HashMultiTree() {std::cout<<"oop::~HashMultiTree"<<std::endl;}
	};


};

#endif