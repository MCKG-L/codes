
    l = 1,r = m;
    while(l < r){
        int mid = l + r + 1 >> 1;
        a[1] = mid;
        for(int i=2;i<=n;i++) a[i] = c[i];
        sort(a+1,a+1+n);
        if(check(ans)){
            l = mid;
        }else r = mid - 1;
    }
    cout << ans * l + (ans + 1) * (m - l) << endl;
