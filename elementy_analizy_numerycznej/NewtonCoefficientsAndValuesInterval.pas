unit NewtonCoefficientsAndValuesInterval;

interface

uses IntervalArithmetic;

function NewtonCoefficientsInterval(n : Integer; x : TArray<Interval>; f : TArray<Interval>; var st : Integer) : TArray<Interval>;
function NewtonValueInterval(n : Integer; x : TArray<Interval>; f : TArray<Interval>; point : Interval; var st : Integer) : Interval;

implementation

function NewtonCoefficientsInterval(n : Integer; x : TArray<Interval>; f : TArray<Interval>; var st : Integer) : TArray<Interval>;
var i,j : Integer;
    tempArray : TArray<Interval>;

begin

  if n<0 then
  begin
    st:=1;
    Result:=f;
    Exit;
  end;

  for i:=0 to n-1 do
    for j:=i+1 to n do
      if (x[i].a=x[j].a) and (x[i].b=x[j].b) then
      begin
        st:=2;
        Result:=f;
        Exit;
      end;

  st:=0;
  SetLength(tempArray,Length(f));
  for i:=Low(f) to High(f) do
    tempArray[i]:=f[i];

  for j:=1 to n do
    for i:=0 to n-j do
      tempArray[i]:=idiv(isub(tempArray[i+1],tempArray[i]),isub(x[i+j],x[i]));

    for i:=1 to n do
      for j:=i downto 1 do
        tempArray[j]:=isub(tempArray[j],imul(tempArray[j-1],x[i]));

  Result := tempArray;

end;

function NewtonValueInterval(n : Integer; x : TArray<Interval>; f : TArray<Interval>; point : Interval; var st : Integer) : Interval;
var i, j : Integer;
    value : interval;
    tempArray : TArray<interval>;

begin

  if n<0 then
  begin
    st:=1;
    Result:=int_read('0');
    Exit;
  end;

  for i:=0 to n-1 do
    for j:=i+1 to n do
      if (x[i].a=x[j].a) and (x[i].b=x[j].b) then
      begin
        st:=2;
        Result:=int_read('0');
        Exit;
      end;

  st:=0;
  SetLength(tempArray,Length(f));
  for i:=Low(f) to High(f) do
    tempArray[i]:=f[i];

  for j:=1 to n do
    for i:=0 to n-j do
      tempArray[i]:=idiv(isub(tempArray[i+1],tempArray[i]),isub(x[i+j],x[i]));

  value:=tempArray[0];

    for i:=1 to n do
      value := iadd(imul(value,isub(point, x[i])),tempArray[i]);

  Result:=value;

end;

end.
