var
  n,m:longint;
  s:real;
begin
  assign(input,'minnum.in');
  assign(output,'minnum.out');
  reset(input);
  rewrite(output);
  read(n);
  while s<=n do
    begin
      inc(m);
      s:=s+1/m;
    end;
  writeln(m);
  close(input);
  close(output);
end.
