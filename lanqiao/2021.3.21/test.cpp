#include <iostream>
using namespace std;
const int maxn = 13010;
int n, W, w[maxn], v[maxn], f[maxn];
int main() {
  std::cin >> n >> W;
  for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];
  for (int i = 1; i <= n; i++)
    for (int l = W; l >= w[i]; l--){
      if (f[l - w[i]] + v[i] > f[l]) f[l] = f[l - w[i]] + v[i];
      cout<<w[i]<<"_____"<<l<<"----"<<l - w[i]<<"==="<<f[l - w[i]] + v[i]<<"+++"<<f[l]<<endl;
	}
  cout << f[W];
  return 0;
}
