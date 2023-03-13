#include "stdc++.h"
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    double n;

    void read_input() {
        ifstream fin("in");
        fin >> n;
        fin.close();
    }

    double get_result() {
        double precission = 0.001; // this is hardcoded as required
        double newN = n;
        int pow10 = 0;
        // make the number >= 1
        while (newN < 1) {
            newN *= 10;
            pow10++; // store it to reconstruct number
            precission *= 10; // update precission
        }

        int noSteps = 1;
        double left = 1;
        double right = newN;
        while (left <= right) {
            cout << "Step " << noSteps << endl;
            cout << "Interval (" << left << "," << right << ")" << endl;
            double mid = (left + right) / 2;
            double res = mid * mid; // try the mid value
            double diff = res-newN;
            if (fabs(diff) < precission) {
                // reconstructor number
                for (int i = 0; i < pow10; i++) {
                    mid /= 10;
                }
                return mid;
            }
            // update intervals where to look for the number
            if (res > newN) {
                right = mid;
            } else {
                left = mid;
            }
            if (noSteps++ > 100)  {
                cout << "Too many steps!!! Something is wrong";
                break;
            }
        }

        // Precizie de 10^-x = |rezultatul vostru - rezultatul corect| <= 10^-x
        return 0.0;
    }

    void print_output(double result) {
        ofstream fout("out");
        fout << setprecision(4) << fixed << result;
        fout.close();
    }
};

// [ATENTIE] NU modifica functia main!
int main() {
    // * se aloca un obiect Task pe heap
    // (se presupune ca e prea mare pentru a fi alocat pe stiva)
    // * se apeleaza metoda solve()
    // (citire, rezolvare, printare)
    // * se distruge obiectul si se elibereaza memoria
    auto* task = new (nothrow) Task(); // hint: cppreference/nothrow
    if (!task) {
        cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
