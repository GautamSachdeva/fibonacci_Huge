#include <iostream>
using namespace std;


long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
	long long count = 2;
	bool flag_1 = false;
    for (long long i = 0; i = -1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        if(flag_1 == true){
        	if(current%m == 1){
        		count++;
        		break;
			}
			else{
				flag_1 = false;
			}
		}
		if(current%m == 0){
			flag_1 = true;
		}
		count++;	
    }
	long long fib_mirror = n%(count-2);
	int* array = new int[fib_mirror+5];
	array[0] = 0;
	array[1] = 1;
	for(long long j = 2 ; j < fib_mirror+2 ; j++){
		array[j] = array[j-1] + array[j-2];
	}
	long long answer = array[fib_mirror];
	delete[] array;
	
    return answer%m;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
