unit NewtonCoefficientsAndValues;

interface

function NewtonCoefficientsExtended(n : Integer; x : TArray<Extended>; f : TArray<Extended>; var st : Integer) : TArray<Extended>;
function NewtonValueExtended(n : Integer; x : TArray<Extended>; f : TArray<Extended>; point : Extended; var st : Integer) : Extended;

implementation

function NewtonCoefficientsExtended(n : Integer; x : TArray<Extended>; f : TArray<Extended>; var st : Integer) : TArray<Extended>;
var i,j : Integer;
    tempArray : TArray<Extended>;

begin

  if n<0 then
  begin
    st:=1;
    Result:=f;
    Exit;
  end;

  for i:=0 to n-1 do
    for j:=i+1 to n do
      if x[i]=x[j] then
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
      tempArray[i]:=(tempArray[i+1]-tempArray[i])/(x[i+j]-x[i]);

  for i:=1 to n do
    for j:=i downto 1 do
      tempArray[j]:=tempArray[j]-tempArray[j-1]*x[i];

  Result := tempArray;

end;

function NewtonValueExtended(n : Integer; x : TArray<Extended>; f : TArray<Extended>; point : Extended; var st : Integer) : Extended;
var i, j : Integer;
    value : Extended;
    tempArray : TArray<Extended>;

begin

  if n<0 then
  begin
    st:=1;
    Result:=0;
    Exit;
  end;

  for i:=0 to n-1 do
    for j:=i+1 to n do
      if x[i]=x[j] then
      begin
        st:=2;
        Result:=0;
        Exit;
      end;

  st:=0;
  SetLength(tempArray,Length(f));
  for i:=Low(f) to High(f) do
    tempArray[i]:=f[i];

  for j:=1 to n do
    for i:=0 to n-j do
      tempArray[i]:=(tempArray[i+1]-tempArray[i])/(x[i+j]-x[i]);

  value:=tempArray[0];

  for i:=1 to n do
    value := value * (point - x[i]) + tempArray[i];

  Result:=value;

end;

end.

