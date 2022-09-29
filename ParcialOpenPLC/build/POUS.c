void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PYTHON_EVAL_init__(PYTHON_EVAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_EVAL_body__(PYTHON_EVAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(0, data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_EVAL_body__() 





void PYTHON_POLL_init__(PYTHON_POLL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->STATE,0,retain)
  __INIT_VAR(data__->BUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->PREBUFFER,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->TRIGM1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TRIGGED,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_POLL_body__(PYTHON_POLL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __IL_DEFVAR_T __IL_DEFVAR;
  __IL_DEFVAR_T __IL_DEFVAR_BACK;
  #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
  #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)
extern void __PythonEvalFB(int, PYTHON_EVAL*);__PythonEvalFB(1,(PYTHON_EVAL*)(void*)data__);
  #undef GetFbVar
  #undef SetFbVar
;

  goto __end;

__end:
  return;
} // PYTHON_POLL_body__() 





void PYTHON_GEAR_init__(PYTHON_GEAR *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->N,0,retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CODE,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->ACK,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESULT,__STRING_LITERAL(0,""),retain)
  PYTHON_EVAL_init__(&data__->PY_EVAL,retain);
  __INIT_VAR(data__->COUNTER,0,retain)
  __INIT_VAR(data__->ADD10_OUT,0,retain)
  __INIT_VAR(data__->EQ13_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SEL15_OUT,0,retain)
  __INIT_VAR(data__->AND7_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PYTHON_GEAR_body__(PYTHON_GEAR *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,ADD10_OUT,,ADD__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->COUNTER,),
    (UINT)1));
  __SET_VAR(data__->,EQ13_OUT,,EQ__BOOL__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (UINT)__GET_VAR(data__->N,),
    (UINT)__GET_VAR(data__->ADD10_OUT,)));
  __SET_VAR(data__->,SEL15_OUT,,SEL__UINT__BOOL__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (UINT)__GET_VAR(data__->ADD10_OUT,),
    (UINT)0));
  __SET_VAR(data__->,COUNTER,,__GET_VAR(data__->SEL15_OUT,));
  __SET_VAR(data__->,AND7_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->EQ13_OUT,),
    (BOOL)__GET_VAR(data__->TRIG,)));
  __SET_VAR(data__->PY_EVAL.,TRIG,,__GET_VAR(data__->AND7_OUT,));
  __SET_VAR(data__->PY_EVAL.,CODE,,__GET_VAR(data__->CODE,));
  PYTHON_EVAL_body__(&data__->PY_EVAL);
  __SET_VAR(data__->,ACK,,__GET_VAR(data__->PY_EVAL.ACK,));
  __SET_VAR(data__->,RESULT,,__GET_VAR(data__->PY_EVAL.RESULT,));

  goto __end;

__end:
  return;
} // PYTHON_GEAR_body__() 





void PARCIAL1_init__(PARCIAL1 *data__, BOOL retain) {
  __INIT_VAR(data__->PRENDIDO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORCARROENTRADA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->SENSORCARROSALIDA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RETIRARTICKET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->VALIDARTICKET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->IR_RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PROCESO1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ERROR1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ERROR2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUERTAENTRADA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->PUERTASALIDA,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->TON_ENTRADA,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->TON_SALIDA,__time_to_timespec(1, 0, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->CONTADORENTRADA,0,retain)
  __INIT_VAR(data__->CONTADORSALIDA,0,retain)
  TON_init__(&data__->TON0,retain);
  CTU_init__(&data__->CTU0,retain);
  TON_init__(&data__->TON1,retain);
  CTU_init__(&data__->CTU1,retain);
  R_TRIG_init__(&data__->R_TRIG1,retain);
  R_TRIG_init__(&data__->R_TRIG2,retain);
}

// Code part
void PARCIAL1_body__(PARCIAL1 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,ERROR1,,(((__GET_VAR(data__->RETIRARTICKET,) && !(__GET_VAR(data__->SENSORCARROENTRADA,))) && !(__GET_VAR(data__->IR_RESET,))) && __GET_VAR(data__->PRENDIDO,)));
  if (((((__GET_VAR(data__->RETIRARTICKET,) && __GET_VAR(data__->SENSORCARROENTRADA,)) && !(__GET_VAR(data__->ERROR1,))) && !(__GET_VAR(data__->IR_RESET,))) && __GET_VAR(data__->PRENDIDO,))) {
    __SET_VAR(data__->,PUERTAENTRADA,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TON0.,IN,,(!(__GET_VAR(data__->SENSORCARROENTRADA,)) && __GET_VAR(data__->PRENDIDO,)));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TON_body__(&data__->TON0);
  if (((__GET_VAR(data__->IR_RESET,) && __GET_VAR(data__->PRENDIDO,)) || __GET_VAR(data__->TON0.Q,))) {
    __SET_VAR(data__->,PUERTAENTRADA,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,TON_ENTRADA,,__GET_VAR(data__->TON0.ET,));
  __SET_VAR(data__->,PROCESO1,,((__GET_VAR(data__->IR_RESET,) && __GET_VAR(data__->PRENDIDO,)) || __GET_VAR(data__->TON0.Q,)));
  __SET_VAR(data__->R_TRIG1.,CLK,,(__GET_VAR(data__->PUERTAENTRADA,) && __GET_VAR(data__->PRENDIDO,)));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,(__GET_VAR(data__->IR_RESET,) && __GET_VAR(data__->PRENDIDO,)));
  __SET_VAR(data__->CTU0.,PV,,10);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,CONTADORENTRADA,,__GET_VAR(data__->CTU0.CV,));
  __SET_VAR(data__->,ERROR2,,(((__GET_VAR(data__->VALIDARTICKET,) && !(__GET_VAR(data__->SENSORCARROSALIDA,))) && !(__GET_VAR(data__->IR_RESET,))) && __GET_VAR(data__->PRENDIDO,)));
  if ((((((__GET_VAR(data__->VALIDARTICKET,) && __GET_VAR(data__->SENSORCARROSALIDA,)) && !(__GET_VAR(data__->ERROR2,))) && !(__GET_VAR(data__->IR_RESET,))) && __GET_VAR(data__->PROCESO1,)) && __GET_VAR(data__->PRENDIDO,))) {
    __SET_VAR(data__->,PUERTASALIDA,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TON1.,IN,,(!(__GET_VAR(data__->SENSORCARROSALIDA,)) && __GET_VAR(data__->PRENDIDO,)));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 5, 0, 0, 0));
  TON_body__(&data__->TON1);
  if (((__GET_VAR(data__->IR_RESET,) && __GET_VAR(data__->PRENDIDO,)) || __GET_VAR(data__->TON1.Q,))) {
    __SET_VAR(data__->,PUERTASALIDA,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,TON_SALIDA,,__GET_VAR(data__->TON1.ET,));
  __SET_VAR(data__->R_TRIG2.,CLK,,(__GET_VAR(data__->PUERTASALIDA,) && __GET_VAR(data__->PRENDIDO,)));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU1.,R,,(__GET_VAR(data__->IR_RESET,) && __GET_VAR(data__->PRENDIDO,)));
  __SET_VAR(data__->CTU1.,PV,,10);
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->,CONTADORSALIDA,,__GET_VAR(data__->CTU1.CV,));
  __SET_VAR(data__->,IR_RESET,,(__GET_VAR(data__->RESET,) && __GET_VAR(data__->PRENDIDO,)));

  goto __end;

__end:
  return;
} // PARCIAL1_body__() 





