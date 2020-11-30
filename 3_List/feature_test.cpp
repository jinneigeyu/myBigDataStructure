#include <future>
#include <iostream>
#include <mutex>
#include <condition_variable>

int find_the_answer_to_ltuae(int input);
void do_other_stuff();
std::mutex _sync;
std::condition_variable cv;
int main()
{
    // std::future<int> the_answer=std::async(find_the_answer_to_ltuae,50);
    // do_other_stuff();
    // std::cout<<"the answer is "<<the_answer.get()<<"\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << "out block -start" << i << "\n";

        {
            std::unique_lock<std::mutex> lc(_sync);
            cv.wait(lc);
            std::cout << "in block" << i << " \n";
        }

        std::cout << "out block -end" << i << "\n";
    }
    return 1;
}

int find_the_answer_to_ltuae(int input)
{
    std::cout << "find answer \n";
    return input;
}

void do_other_stuff()
{
    std::cout << "do othre \n";
}