program land(input,output);
var n,i,j,len:longint;
    a:array[1..1000] of longint;
begin
  assign(input,'land.in');
  assign(output,'land.out');
  reset(input); rewrite(output);

  readln(n);
  n:=n*n;
  fillchar(a,sizeof(a),0);
  a[1]:=1; len:=1;
  for i:=1 to n do begin
    for j:=1 to len do a[j]:=a[j] shl 1;
    for j:=1 to len do
      if a[j]>=10 then begin
        a[j]:=a[j] mod 10;
        inc(a[j+1]) ;
      end;
    if a[len+1]>0 then inc(len);
  end;
  dec(a[1]);
  for i:=len downto 1 do write(a[i]);
  writeln;
  close(input); close(output);
end.
