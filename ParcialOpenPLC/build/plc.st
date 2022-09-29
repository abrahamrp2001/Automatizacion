TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK



FUNCTION_BLOCK python_eval
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_poll
  VAR_INPUT
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    STATE : DWORD;
    BUFFER : STRING;
    PREBUFFER : STRING;
    TRIGM1 : BOOL;
    TRIGGED : BOOL;
  END_VAR

  {extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);}
END_FUNCTION_BLOCK

FUNCTION_BLOCK python_gear
  VAR_INPUT
    N : UINT;
    TRIG : BOOL;
    CODE : STRING;
  END_VAR
  VAR_OUTPUT
    ACK : BOOL;
    RESULT : STRING;
  END_VAR
  VAR
    py_eval : python_eval;
    COUNTER : UINT;
    ADD10_OUT : UINT;
    EQ13_OUT : BOOL;
    SEL15_OUT : UINT;
    AND7_OUT : BOOL;
  END_VAR

  ADD10_OUT := ADD(COUNTER, 1);
  EQ13_OUT := EQ(N, ADD10_OUT);
  SEL15_OUT := SEL(EQ13_OUT, ADD10_OUT, 0);
  COUNTER := SEL15_OUT;
  AND7_OUT := AND(EQ13_OUT, TRIG);
  py_eval(TRIG := AND7_OUT, CODE := CODE);
  ACK := py_eval.ACK;
  RESULT := py_eval.RESULT;
END_FUNCTION_BLOCK


PROGRAM Parcial1
  VAR
    Prendido : BOOL;
  END_VAR
  VAR
    Reset : BOOL := FALSE;
  END_VAR
  VAR
    SensorCarroEntrada : BOOL;
    SensorCarroSalida : BOOL;
    RetirarTicket : BOOL;
    ValidarTicket : BOOL;
  END_VAR
  VAR
    IR_Reset : BOOL;
    Proceso1 : BOOL;
  END_VAR
  VAR
    Error1 : BOOL;
    Error2 : BOOL;
    PuertaEntrada : BOOL;
    PuertaSalida : BOOL;
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
