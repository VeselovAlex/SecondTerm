TEMPLATE = app
CONFIG += console
CONFIG += qtestlib

SOURCES += main.cpp \
    ExprTree.cpp

HEADERS += \
    BinaryTreeNode.h \
    Tests/NodeTest.h \
    Tree.h \
    BinarySearchTree.h \
    Tests/BSTTest.h \
    ExprTree.h \
    Tests/ExprTreeTest.h

