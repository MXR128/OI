var
        i,j,n,m,min,max:longint;
        f1:boolean;
        a,b,t:array[1..1000] of longint;
        f:array[0..1500] of longint;
begin
        assign(input,'work.in');reset(input);
        assign(output,'work.out');rewrite(output);

        readln(n);
        min := maxlongint;
        for i := 1 to n do
        begin
                read(t[i],a[i],b[i]);
                if a[i]<min then min := a[i];
                if b[i]>max then max := b[i];
        end;
        for i := min to max do  f[i] := maxlongint;
        f[min] := 0;
        for i := min to max do
                if f[i]<>maxlongint then
                begin
                        f1 := false;
                        for j := 1 to n do
                                if (a[j]<=i)and(i+t[j]<=b[j])then
                                begin
                                        if f[i]+t[j]<f[i+t[j]] then     f[i+t[j]] := f[i] + t[j];
                                        f1 := true;
                                end;
                        if f1 then f[i] := maxlongint;
                end;
        m := maxlongint;
        for i := min to max do
                if f[i]<m then m := f[i];
        writeln(m);

        close(input);close(output);
end.


