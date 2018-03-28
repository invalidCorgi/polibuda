unit NewtonCoefficientsAndValues;

interface

uses IntervalArithmetic;

function DividedDiffencesExtended(n : Integer; x : TArray<Extended>; f : TArray<Extended>) : TArray<Extended>;
function NewtonCoefficientsExtended(n : Integer; x : TArray<Extended>; f : TArray<Extended>) : TArray<Extended>;
function NewtonValueExtended(n : Integer; x : TArray<Extended>; f : TArray<Extended>; point : Extended) : Extended;

function DividedDiffencesInterval(n : Integer; x : TArray<Interval>; f : TArray<Interval>) : TArray<Interval>;
function NewtonCoefficientsInterval(n : Integer; x : TArray<Interval>; f : TArray<Interval>) : TArray<Interval>;
function NewtonValueInterval(n : Integer; x : TArray<Interval>; f : TArray<Interval>; point : Interval) : Interval;

implementation

function DividedDiffencesExtended(n : Integer; x : TArray<Extended>; f : TArray<Extended>) : TArray<Extended>;
var i, j : Integer;
    tempArray : TArray<Extended>;

{for i:=n downto 1 do
    for j:=n downto n-i+1 do
      f[j]:=(f[j]-f[j-1]) / (x[j]-x[j-(n-i+1)]);}

begin

  SetLength(tempArray,Length(f));
  for i:=Low(f) to High(f) do
    tempArray[i]:=f[i];

  for j:=1 to n do
    for i:=0 to n-j do
      tempArray[i]:=(tempArray[i+1]-tempArray[i])/(x[i+j]-x[i]);

  Result:=tempArray;

end;

function NewtonCoefficientsExtended(n : Integer; x : TArray<Extended>; f : TArray<Extended>) : TArray<Extended>;
var i,j : Integer;
    tempArray : TArray<Extended>;

begin

  tempArray := DividedDiffencesExtended(n, x, f);

  for i:=1 to n do
    for j:=i downto 1 do
      tempArray[j]:=tempArray[j]-tempArray[j-1]*x[i];

  Result := tempArray;

end;

function NewtonValueExtended(n : Integer; x : TArray<Extended>; f : TArray<Extended>; point : Extended) : Extended;
var i : Integer;
    value : Extended;
    tempArray : TArray<Extended>;

begin

  tempArray := DividedDiffencesExtended(n, x, f);

  value:=tempArray[0];

  for i:=1 to n do
    value := value * (point - x[i]) + tempArray[i];
  Result:=value;

end;

function DividedDiffencesInterval(n : Integer; x : TArray<Interval>; f : TArray<Interval>) : TArray<Interval>;
var i, j : Integer;
    tempArray : TArray<Interval>;

begin

  SetLength(tempArray,Length(f));
  for i:=Low(f) to High(f) do
    tempArray[i]:=f[i];

  for j:=1 to n do
    for i:=0 to n-j do
      tempArray[i]:=idiv(isub(tempArray[i+1],tempArray[i]),isub(x[i+j],x[i]));

  Result:=tempArray;

end;

function NewtonCoefficientsInterval(n : Integer; x : TArray<Interval>; f : TArray<Interval>) : TArray<Interval>;
var i,j : Integer;
    tempArray : TArray<Interval>;

begin

  tempArray := DividedDiffencesInterval(n, x, f);

  for i:=1 to n do
    for j:=i downto 1 do
      tempArray[j]:=isub(tempArray[j],imul(tempArray[j-1],x[i]));

  Result := tempArray;

end;

function NewtonValueInterval(n : Integer; x : TArray<Interval>; f : TArray<Interval>; point : Interval) : Interval;
var i : Integer;
    value : interval;
    tempArray : TArray<interval>;

begin

  tempArray := DividedDiffencesInterval(n, x, f);

  value:=tempArray[0];

  for i:=1 to n do
    value := iadd(imul(value,isub(point, x[i])),tempArray[i]);
  Result:=value;

end;

end.
