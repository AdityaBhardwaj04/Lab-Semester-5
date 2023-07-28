#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    ifstream file("input.txt");
    if(!file.is_open()){
        cerr << "Error opening file \n";
		exit(1);
    }

    int n;
    file >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        file >> arr[i];
    }
    file.close();

    sort(arr.begin(), arr.end());

    cout << "Second Smallest Element: " << arr[1] << endl;
    cout << "Second Largest Element: " << arr[n - 2] << endl;

    return 0;
}