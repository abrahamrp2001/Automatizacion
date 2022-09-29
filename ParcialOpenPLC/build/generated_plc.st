PROGRAM Parcial1
  VAR
    Prendido AT %IX0.0 : BOOL;
  END_VAR
  VAR
    Reset : BOOL := FALSE;
  END_VAR
  VAR
    SensorCarroEntrada AT %IX0.1 : BOOL;
    SensorCarroSalida AT %IX0.2 : BOOL;
    RetirarTicket AT %IX0.3 : BOOL;
    ValidarTicket AT %IX0.4 : BOOL;
  END_VAR
  VAR
    IR_Reset : BOOL;
    Proceso1 : BOOL;
  END_VAR
  VAR
    Error1 AT %QX0.2 : BOOL;
    Error2 AT %QX0.3 : BOOL;
    PuertaEntrada AT %QX0.0 : BOOL;
    PuertaSalida AT %QX0.1 : BOOL;
  END_VAR
  VAR
    TON_Entrada : TIME;
    TON_Salida : TIME;
    ContadorEntrada : INT;
    ContadorSalida : INT;
    TON0 : TON;
    CTU0 : CTU;
    TON1 : TON;
    CTU1 : CTU;
    R_TRIG1 : R_TRIG;
    R_TRIG2 : R_TRIG;
  END_VAR

  Error1 := RetirarTicket AND NOT(SensorCarroEntrada) AND NOT(IR_Reset) AND Prendido;
  IF RetirarTicket AND SensorCarroEntrada AND NOT(Error1) AND NOT(IR_Reset) AND Prendido THEN
    PuertaEntrada := TRUE; (*set*)
  END_IF;
  TON0(IN := NOT(SensorCarroEntrada) AND Prendido, PT := T#5S);
  IF IR_Reset AND Prendido OR TON0.Q THEN
    PuertaEntrada := FALSE; (*reset*)
  END_IF;
  TON_Entrada := TON0.ET;
  Proceso1 := IR_Reset AND Prendido OR TON0.Q;
  R_TRIG1(CLK := PuertaEntrada AND Prendido);
  CTU0(CU := R_TRIG1.Q, R := IR_Reset AND Prendido, PV := 10);
  ContadorEntrada := CTU0.CV;
  Error2 := ValidarTicket AND NOT(SensorCarroSalida) AND NOT(IR_Reset) AND Prendido;
  IF ValidarTicket AND SensorCarroSalida AND NOT(Error2) AND NOT(IR_Reset) AND Proceso1 AND Prendido THEN
    PuertaSalida := TRUE; (*set*)
  END_IF;
  TON1(IN := NOT(SensorCarroSalida) AND Prendido, PT := T#5S);
  IF IR_Reset AND Prendido OR TON1.Q THEN
    PuertaSalida := FALSE; (*reset*)
  END_IF;
  TON_Salida := TON1.ET;
  R_TRIG2(CLK := PuertaSalida AND Prendido);
  CTU1(CU := R_TRIG2.Q, R := IR_Reset AND Prendido, PV := 10);
  ContadorSalida := CTU1.CV;
  IR_Reset := Reset AND Prendido;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : Parcial1;
  END_RESOURCE
END_CONFIGURATION
