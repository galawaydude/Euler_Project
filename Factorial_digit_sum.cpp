#include<iostream>
#include<vector>
using namespace std;
void reverse(vector<int> &ar, int s, int e){
    if (s>=e){
        return;
    }
    swap(ar[s], ar[e]);
    return reverse(ar, s+1, e-1);
}
vector<int> product(vector<int> &ar, int n){
    int carry = 0;
    vector<int> temp;
    for (int i = ar.size()-1; i>=0; i--){
        int prod = n * ar[i] + carry;
        if (prod/10 != 0 && i != 0){
            carry = prod/10;
            temp.push_back(prod%10);
        }
        if (prod/10 !=0 && i==0){
            while (prod>0){
                temp.push_back(prod%10);
                prod = prod/10;
            }
        }
        if (prod/10 == 0 ){
            temp.push_back(prod);
        }
    }
    if (temp[ar.size()-1]== 0){
        temp.pop_back();
    }
    reverse(temp, 0, temp.size()-1);
    return temp;
}
int main(){
    int n;
    cin>>n;
    vector<int> ar;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin>>a;
        ar.push_back(a);
    }
    int a;
    cin>>a;
    vector<int> temp = product(ar, a);

    for (int i = 0; i<temp.size(); i++)
    {
        cout<<temp[i]<<" ";
    }
    
}