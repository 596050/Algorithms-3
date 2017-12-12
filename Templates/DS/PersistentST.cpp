int root[],L[],  R[], sum[];//Check array size, 2*log(MAX) added each time
int insert(int l, int r, int node, int pos, int val){
  if(l > pos or r < pos) return node;
  int cur = ++COUNT;
  if(l == r){ sum[cur] = sum[node] + val; return cur; }
  int mid = (l + r) >> 1;
  L[cur] = insert(l, mid, L[node], pos, val);
  R[cur] = insert(mid + 1, r, R[node], pos, val);
  sum[cur] = sum[L[cur]] + sum[R[cur]]; return cur;
}
int query(int l, int r, int node, int ql, int qr){
  if(l > qr or r < ql) return 0;
  if(l >= ql and r <= qr) return sum[node];
  int mid = (l + r) >> 1, ans = 0;
  if(L[node]) ans += query(l, mid, L[node], ql, qr);
  if(R[node]) ans += query(mid + 1, r, R[node], ql, qr);
  return ans;
}