#define ll long long
#define mod 1000000007

ll query(vector<ll> &segTree,vector<ll> &lzy,ll node,ll s,ll e,ll l,ll r)
{
    if(l>e || r<s)return 0;
    if(lzy[node])
    {
        segTree[node]=(e-s+1)-segTree[node];lzy[node]=0;lzy[2*node+1]^=1;lzy[2*node+2]^=1;
    }
    if(l<=s && r>=e)return segTree[node];
    ll mid=(s+e)/2;
    ll lft=query(segTree,lzy,2*node+1,s,mid,l,r);
    ll rht=query(segTree,lzy,2*node+2,mid+1,e,l,r);
    return lft+rht;
}

ll update(vector<ll> &segTree,vector<ll> &lzy,ll node,ll s,ll e,ll l,ll r)
{
    if(lzy[node]){segTree[node]=(e-s+1)-segTree[node];lzy[2*node+1]^=1;lzy[2*node+2]^=1;lzy[node]=0;}
    if(l>e || r<s)return segTree[node];
    if(l<=s && r>=e)
    {
        segTree[node]=(e-s+1)-segTree[node];lzy[2*node+1]^=1;lzy[2*node+2]^=1;return segTree[node];
    }
    ll mid=(s+e)/2;
    ll lft=update(segTree,lzy,2*node+1,s,mid,l,r);
    ll rht=update(segTree,lzy,2*node+2,mid+1,e,l,r);
    segTree[node]=lft+rht;
    return segTree[node];
}

int Solution::solve(int A, vector<vector<int> > &B) 
{
    vector<ll> segTree(400040,0),lzy(400040,0);ll n=B.size();ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(B[i][0]){ll q=query(segTree,lzy,0,0,A-1,B[i][1],B[i][2]);ans=(ans%mod+q%mod)%mod;}
        else ll u=update(segTree,lzy,0,0,A-1,B[i][1],B[i][2]);
    }
    return ans;
}

