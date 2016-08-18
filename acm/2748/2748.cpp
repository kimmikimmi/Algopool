#include <iostream>
using namespace std;


class SquareMatrix {
public:
	SquareMatrix(int _n);
	int size(void) const;
	SquareMatrix operator * (const SquareMatrix &other);
	long long* operator [] (const int row);
private:
	int n;
	long long **arr;
};

SquareMatrix getIdentity(int n);
SquareMatrix pow(const SquareMatrix &A, long long m);
long long fib(long long n);

const long long MOD = 1000000;


SquareMatrix::SquareMatrix(int _n) {
	n = _n;
	arr = new long long*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new long long[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
}

int SquareMatrix::size(void) const {
	return n;
}

SquareMatrix SquareMatrix::operator * (const SquareMatrix &other) {
	if (n != other.n) throw runtime_error("SizeNotMatched");
	SquareMatrix ret(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				ret[i][j] += (arr[i][k] * other.arr[k][j]) % MOD;
			}
			ret[i][j] %= MOD;
		}
	}
	return ret;
}

long long* SquareMatrix::operator [] (const int row) {
	return arr[row];
}

SquareMatrix getIdentity(int n) {
	SquareMatrix ret(n);
	for (int i = 0; i < n; i++) ret[i][i] = 1;
	return ret;
}

// return A^m
SquareMatrix pow(const SquareMatrix &A, long long m) {
	// base : A^0 = I
	if (m == 0) return getIdentity(A.size());
	if (m % 2 > 0) return pow(A, m - 1) * A;
	SquareMatrix half = pow(A, m / 2);
	// A^m = (A^(m/2)) * (A^(m/2))
	return half * half;
}

long long fib(long long n) {
	if (n == 0) return 0;
	SquareMatrix W(2);
	W[0][0] = 0;
	W[0][1] = W[1][0] = W[1][1] = 1;
	return pow(W, n - 1)[1][1];
}

int main() {
	long long tmp ;
	cin >> tmp;
	cout << fib(tmp) << endl;
	return 0;
}