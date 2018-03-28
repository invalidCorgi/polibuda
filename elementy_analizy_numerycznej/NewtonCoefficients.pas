unit NewtonCoefficients;

interface

procedure NewtonCoefficientsExtended(n : Integer; x : Array of Extended; var f : Array of Extended);

implementation

procedure NewtonCoefficientsExtended(n : Integer; x : Array of Extended; var f : Array of Extended);
var i,j : Integer;
    xi  : Extended;
begin
  for i:=1 to n do
  begin
    xi:=x[i];
    for j:=i downto 1 do
    f[j]:=f[j]-f[j-1]*xi
  end;
end;
end.

