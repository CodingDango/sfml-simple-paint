#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'pageCount' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER p
 */

int pageCount(int n, int p) {
    bool is_left_side = (n / 2) > p;
    int page_counter = 0;
    int current_page = (is_left_side ? 1 : n);
    int page_increment = (is_left_side ? 1 : -1);
    
    for (int curr_page = current_page; curr_page != p; curr_page += page_increment)
    {
        if (current_page % 2 == 0)
            page_counter++;
    }
    
    return page_counter;
}

int main()
{
    constexpr int book_pages = 6;
    constexpr int page_target = 2;

    std::cout << pageCount(book_pages, page_target) << '\n';
}
