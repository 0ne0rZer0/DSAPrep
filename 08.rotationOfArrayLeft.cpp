#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;
#define endl "\n"
#define sd(val) scanf("%d", &val)
#define ss(val) scanf("%s", &val)
#define sl(val) scanf("%lld", &val)
#define debug(val) printf("check%d\n", val)
#define all(v) v.begin(), v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val, 0, sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define ai(arr, n)                       \
    vi arr(n, 0);                        \
    for (int i = 0; i < arr.size(); i++) \
        cin >> arr[i];
#define ao(arr)          \
    for (auto wtf : arr) \
        cout << wtf << " ";

#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void reverseArray(vector<int> &arr, int start, int end)
{
    int temp = 0;
    int left = start;
    int right = end - 1;
    while (left < right)
    {
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}
void rotationArrayLeft(vector<int> &arr, int rotation)
{
    reverseArray(arr, 0, rotation);
    reverseArray(arr, rotation, arr.size());
    reverseArray(arr, 0, arr.size());
}

int main()
{
    FIO
        OJ int size;
    cin >> size;
    vector<int> arr(size);
    for (auto &it : arr)
    {
        cin >> it;
    }
    int rotation = 0;
    cin >> rotation;
    rotationArrayLeft(arr, rotation);
    for(auto i : arr) {
        cout << i << " ";
    }
    return 0;
}