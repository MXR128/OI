var
  a:real;
  k,n,i:integer;
begin
  assign(input,'minnum.in');
  assign(output,'minnum.out');
  reset(input);
  rewrite(output);
  readln(k);
  a:=0;
  n:=1;
  while a<=k do
    begin
      a:=a+1/n;
      inc(n);
    end;
  write(n-1);
  close(input);
  close(output);
end.