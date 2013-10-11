#include "stdafx.h"
//#include "CppUnitTest.h"
//
//#include "../util/nav/unused/GridNode.hpp"
//#include "../util/nav/unused/GridLocation.hpp"
//
//
//using namespace Microsoft::VisualStudio::CppUnitTestFramework;
//
//namespace tests
//{		
//	TEST_CLASS(UnitTest1)
//	{		
//		TEST_METHOD(GridNode_create)
//		{
//			GridNode node(GridLocation(1, 1), 50, 100);
//		}
//
//		TEST_METHOD(GridNode_getSetUp)
//		{
//			GridNode node(GridLocation(1, 1), 50, 100);
//			Assert::IsNull(node.getUp().getNode());
//
//			GridNode* gn = new GridNode(GridLocation(1, 2), 100, 125);
//			node.setUp(Edge(*gn, 500));
//			Assert::IsNotNull(node.getUp().getNode());
//		}
//
//		TEST_METHOD(GridNode_getSetDown)
//		{
//			GridNode node(GridLocation(1, 1), 50, 100);
//			Assert::IsNull(node.getDown().getNode());
//
//			GridNode* gn = new GridNode(GridLocation(1, 2), 100, 125);
//			node.setDown(Edge(*gn, 500));
//			Assert::IsNotNull(node.getDown().getNode());
//		}
//
//		TEST_METHOD(GridNode_getSetRight)
//		{
//			GridNode node(GridLocation(1, 1), 50, 100);
//			Assert::IsNull(node.getRight().getNode());
//
//			GridNode* gn = new GridNode(GridLocation(1, 2), 100, 125);
//			node.setRight(Edge(*gn, 500));
//			Assert::IsNotNull(node.getRight().getNode());
//		}
//
//		TEST_METHOD(GridNode_getSetLeft)
//		{
//			GridNode node(GridLocation(1, 1), 50, 100);
//			Assert::IsNull(node.getLeft().getNode());
//
//			GridNode* gn = new GridNode(GridLocation(1, 2), 100, 125);
//			node.setLeft(Edge(*gn, 500));
//			Assert::IsNotNull(node.getLeft().getNode());
//		}
//
//		TEST_METHOD(GridNode_getX)
//		{
//			GridNode node(GridLocation(1, 1), 50, 100);
//			Assert::AreEqual(node.getX(), 50u);
//		}
//
//		TEST_METHOD(GridNode_getY)
//		{
//			GridNode node(GridLocation(1, 1), 50, 100);
//			Assert::AreEqual(node.getY(), 100u);
//		}
//	};
//}