#include <list/LinkedList.h>
#include <gtest/gtest.h>
#include <list>

TEST(LinkedList, not_looped) {
    my_list::LinkedList mList = my_list::LinkedList<int>();
    mList.push_back(1);
    mList.push_back(2);
    mList.push_back(3);
    mList.push_back(5);

    EXPECT_FALSE(mList.isLooped());
}

TEST(LinkedList, not_looped_empty_list) {
    my_list::LinkedList mList = my_list::LinkedList<int>();

    EXPECT_FALSE(mList.isLooped());
}

TEST(LinkedList, looped) {
    my_list::LinkedList mList = my_list::LinkedList<int>();
    mList.push_back(1);
    mList.push_back(2);
    mList.push_back(3);
    mList.push_back(5);
    mList.make_loop();

    EXPECT_TRUE(mList.isLooped());
}
