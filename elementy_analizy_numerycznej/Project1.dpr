program Project1;

uses
  Vcl.Forms,
  MainUnit in 'MainUnit.pas' {MainFrame},
  DataInput in 'DataInput.pas' {Form2},
  IntervalArithmetic in 'IntervalArithmetic.pas',
  NewtonCoefficientsAndValues in 'NewtonCoefficientsAndValues.pas',
  NewtonCoefficientsAndValuesInterval in 'NewtonCoefficientsAndValuesInterval.pas';

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TMainFrame, MainFrame);
  Application.CreateForm(TForm2, Form2);
  Application.Run;
end.
