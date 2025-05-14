void SCALE_TO_REAL_init__(SCALE_TO_REAL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->RAW_INPUT_VALUE,0,retain)
  __INIT_VAR(data__->SCALED_REAL,0,retain)
  __INIT_VAR(data__->REAL_MAX,0,retain)
  __INIT_VAR(data__->REAL_MIN,0,retain)
  __INIT_VAR(data__->RAW_MAX,65535,retain)
  __INIT_VAR(data__->RAW_MIN,0,retain)
  __INIT_VAR(data__->RATE,0,retain)
  __INIT_VAR(data__->OFFSET,0,retain)
}

// Code part
void SCALE_TO_REAL_body__(SCALE_TO_REAL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,RATE,,((__GET_VAR(data__->REAL_MAX,) - __GET_VAR(data__->REAL_MIN,)) / UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)(__GET_VAR(data__->RAW_MAX,) - __GET_VAR(data__->RAW_MIN,)))));
  __SET_VAR(data__->,OFFSET,,(__GET_VAR(data__->REAL_MIN,) - (UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->RAW_MIN,)) * __GET_VAR(data__->RATE,))));
  __SET_VAR(data__->,SCALED_REAL,,((UINT_TO_REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->RAW_INPUT_VALUE,)) * __GET_VAR(data__->RATE,)) + __GET_VAR(data__->OFFSET,)));

  goto __end;

__end:
  return;
} // SCALE_TO_REAL_body__() 





void SCALE_TO_UINT_init__(SCALE_TO_UINT *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->REAL_IN,0,retain)
  __INIT_VAR(data__->UINT_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV1_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL4_OUT,0,retain)
  __INIT_VAR(data__->_TMP_REAL_TO_UINT6_OUT,0,retain)
}

// Code part
void SCALE_TO_UINT_body__(SCALE_TO_UINT *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_DIV1_OUT,,DIV__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->REAL_IN,),
    (REAL)100.0));
  __SET_VAR(data__->,_TMP_MUL4_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_DIV1_OUT,),
    (REAL)65535.0));
  __SET_VAR(data__->,_TMP_REAL_TO_UINT6_OUT,,REAL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_MUL4_OUT,)));
  __SET_VAR(data__->,UINT_OUT,,__GET_VAR(data__->_TMP_REAL_TO_UINT6_OUT,));

  goto __end;

__end:
  return;
} // SCALE_TO_UINT_body__() 





void FLOW_CONTROL_init__(FLOW_CONTROL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->FLOW_K,1.0,retain)
  __INIT_VAR(data__->FLOW_TI,999.0,retain)
  __INIT_VAR(data__->FLOW_TD,0.0,retain)
  __INIT_VAR(data__->PRODUCT_FLOW,6554,retain)
  __INIT_VAR(data__->PRODUCT_FLOW_REAL,100.0,retain)
  __INIT_VAR(data__->CYCLE_TIME,__time_to_timespec(1, 50, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->POS_UPDATE_REAL,0.0,retain)
  __INIT_VAR(data__->CURR_POS_REAL,60.9,retain)
  __INIT_VAR(data__->NEW_POS,35000,retain)
  __INIT_VAR(data__->CURR_POS,35000,retain)
  __INIT_VAR(data__->FLOW_SET_REAL,100.0,retain)
  __INIT_VAR(data__->FLOW_SET_IN,6554,retain)
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL0,retain);
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL1,retain);
  __INIT_VAR(data__->FLOW_MAX,500.0,retain)
  __INIT_VAR(data__->FLOW_MIN,0.0,retain)
  __INIT_VAR(data__->POS_MIN,0.0,retain)
  __INIT_VAR(data__->POS_MAX,100.0,retain)
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL2,retain);
  SCALE_TO_UINT_init__(&data__->SCALE_TO_UINT0,retain);
  __INIT_VAR(data__->_TMP_SUB59_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL60_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD58_OUT,0,retain)
  __INIT_VAR(data__->_TMP_LIMIT40_OUT,0,retain)
}

// Code part
void FLOW_CONTROL_body__(FLOW_CONTROL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_SUB59_OUT,,SUB__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->FLOW_SET_REAL,),
    (REAL)__GET_VAR(data__->PRODUCT_FLOW_REAL,)));
  __SET_VAR(data__->,_TMP_MUL60_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_SUB59_OUT,),
    (REAL)__GET_VAR(data__->FLOW_K,)));
  __SET_VAR(data__->,POS_UPDATE_REAL,,__GET_VAR(data__->_TMP_MUL60_OUT,));
  __SET_VAR(data__->SCALE_TO_REAL0.,RAW_INPUT_VALUE,,__GET_VAR(data__->PRODUCT_FLOW,));
  __SET_VAR(data__->SCALE_TO_REAL0.,REAL_MAX,,__GET_VAR(data__->FLOW_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL0.,REAL_MIN,,__GET_VAR(data__->FLOW_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL0);
  __SET_VAR(data__->,PRODUCT_FLOW_REAL,,__GET_VAR(data__->SCALE_TO_REAL0.SCALED_REAL,));
  __SET_VAR(data__->SCALE_TO_REAL1.,RAW_INPUT_VALUE,,__GET_VAR(data__->FLOW_SET_IN,));
  __SET_VAR(data__->SCALE_TO_REAL1.,REAL_MAX,,__GET_VAR(data__->FLOW_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL1.,REAL_MIN,,__GET_VAR(data__->FLOW_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL1);
  __SET_VAR(data__->,FLOW_SET_REAL,,__GET_VAR(data__->SCALE_TO_REAL1.SCALED_REAL,));
  __SET_VAR(data__->SCALE_TO_REAL2.,RAW_INPUT_VALUE,,__GET_VAR(data__->CURR_POS,));
  __SET_VAR(data__->SCALE_TO_REAL2.,REAL_MAX,,__GET_VAR(data__->POS_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL2.,REAL_MIN,,__GET_VAR(data__->POS_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL2);
  __SET_VAR(data__->,CURR_POS_REAL,,__GET_VAR(data__->SCALE_TO_REAL2.SCALED_REAL,));
  __SET_VAR(data__->,_TMP_ADD58_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->CURR_POS_REAL,),
    (REAL)__GET_VAR(data__->POS_UPDATE_REAL,)));
  __SET_VAR(data__->,_TMP_LIMIT40_OUT,,LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->POS_MIN,),
    (REAL)__GET_VAR(data__->_TMP_ADD58_OUT,),
    (REAL)__GET_VAR(data__->POS_MAX,)));
  __SET_VAR(data__->SCALE_TO_UINT0.,REAL_IN,,__GET_VAR(data__->_TMP_LIMIT40_OUT,));
  SCALE_TO_UINT_body__(&data__->SCALE_TO_UINT0);
  __SET_VAR(data__->,NEW_POS,,__GET_VAR(data__->SCALE_TO_UINT0.UINT_OUT,));

  goto __end;

__end:
  return;
} // FLOW_CONTROL_body__() 





void COMPOSITION_CONTROL_init__(COMPOSITION_CONTROL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->A_IN_PURGE_REAL,47.00,retain)
  __INIT_VAR(data__->A_IN_PURGE,32000,retain)
  __INIT_VAR(data__->A_SETPOINT_REAL,47.00,retain)
  __INIT_VAR(data__->A_SETPOINT,32000,retain)
  __INIT_VAR(data__->CURR_POS,16000,retain)
  __INIT_VAR(data__->VALVE_POS_REAL,25.0,retain)
  __INIT_VAR(data__->POS_UPDATE_REAL,0.0,retain)
  __INIT_VAR(data__->VALVE_POS_NOMINAL,25.0,retain)
  __INIT_VAR(data__->NEW_POS,16000,retain)
  __INIT_VAR(data__->COMPOSITION_K,1.0,retain)
  __INIT_VAR(data__->COMPOSITION_TI,99.0,retain)
  __INIT_VAR(data__->CYCLE_TIME,__time_to_timespec(1, 50, 0, 0, 0, 0),retain)
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL3,retain);
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL2,retain);
  SCALE_TO_UINT_init__(&data__->SCALE_TO_UINT0,retain);
  __INIT_VAR(data__->COMP_MAX,100.0,retain)
  __INIT_VAR(data__->COMP_MIN,0.0,retain)
  __INIT_VAR(data__->POS_MAX,100.0,retain)
  __INIT_VAR(data__->POS_MIN,0.0,retain)
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL0,retain);
  __INIT_VAR(data__->_TMP_SUB45_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL46_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD42_OUT,0,retain)
  __INIT_VAR(data__->_TMP_LIMIT44_OUT,0,retain)
}

// Code part
void COMPOSITION_CONTROL_body__(COMPOSITION_CONTROL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_SUB45_OUT,,SUB__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->A_SETPOINT_REAL,),
    (REAL)__GET_VAR(data__->A_IN_PURGE_REAL,)));
  __SET_VAR(data__->,_TMP_MUL46_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_SUB45_OUT,),
    (REAL)__GET_VAR(data__->COMPOSITION_K,)));
  __SET_VAR(data__->,POS_UPDATE_REAL,,__GET_VAR(data__->_TMP_MUL46_OUT,));
  __SET_VAR(data__->SCALE_TO_REAL3.,RAW_INPUT_VALUE,,__GET_VAR(data__->A_IN_PURGE,));
  __SET_VAR(data__->SCALE_TO_REAL3.,REAL_MAX,,__GET_VAR(data__->COMP_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL3.,REAL_MIN,,__GET_VAR(data__->COMP_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL3);
  __SET_VAR(data__->,A_IN_PURGE_REAL,,__GET_VAR(data__->SCALE_TO_REAL3.SCALED_REAL,));
  __SET_VAR(data__->SCALE_TO_REAL2.,RAW_INPUT_VALUE,,__GET_VAR(data__->A_SETPOINT,));
  __SET_VAR(data__->SCALE_TO_REAL2.,REAL_MAX,,__GET_VAR(data__->COMP_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL2.,REAL_MIN,,__GET_VAR(data__->COMP_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL2);
  __SET_VAR(data__->,A_SETPOINT_REAL,,__GET_VAR(data__->SCALE_TO_REAL2.SCALED_REAL,));
  __SET_VAR(data__->,_TMP_ADD42_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->VALVE_POS_REAL,),
    (REAL)__GET_VAR(data__->POS_UPDATE_REAL,)));
  __SET_VAR(data__->,_TMP_LIMIT44_OUT,,LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->POS_MIN,),
    (REAL)__GET_VAR(data__->_TMP_ADD42_OUT,),
    (REAL)__GET_VAR(data__->POS_MAX,)));
  __SET_VAR(data__->SCALE_TO_UINT0.,REAL_IN,,__GET_VAR(data__->_TMP_LIMIT44_OUT,));
  SCALE_TO_UINT_body__(&data__->SCALE_TO_UINT0);
  __SET_VAR(data__->,NEW_POS,,__GET_VAR(data__->SCALE_TO_UINT0.UINT_OUT,));
  __SET_VAR(data__->SCALE_TO_REAL0.,RAW_INPUT_VALUE,,__GET_VAR(data__->CURR_POS,));
  __SET_VAR(data__->SCALE_TO_REAL0.,REAL_MAX,,__GET_VAR(data__->POS_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL0.,REAL_MIN,,__GET_VAR(data__->POS_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL0);
  __SET_VAR(data__->,VALVE_POS_REAL,,__GET_VAR(data__->SCALE_TO_REAL0.SCALED_REAL,));

  goto __end;

__end:
  return;
} // COMPOSITION_CONTROL_body__() 





void PRESSURE_CONTROL_init__(PRESSURE_CONTROL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PRESSURE_REAL,2700.0,retain)
  __INIT_VAR(data__->PRESSURE,58981,retain)
  __INIT_VAR(data__->PRESSURE_SP_REAL,2700.0,retain)
  __INIT_VAR(data__->PRESSURE_SP,58981,retain)
  __INIT_VAR(data__->CURR_POS,30000,retain)
  __INIT_VAR(data__->VALVE_POS_REAL,39.25,retain)
  __INIT_VAR(data__->POS_UPDATE_REAL,0.0,retain)
  __INIT_VAR(data__->VALVE_POS_NOMINAL,39.25,retain)
  __INIT_VAR(data__->VALVE_POS,25886,retain)
  __INIT_VAR(data__->PRESSURE_K,20.0,retain)
  __INIT_VAR(data__->PRESSURE_TI,999.0,retain)
  __INIT_VAR(data__->CYCLE_TIME,__time_to_timespec(1, 50, 0, 0, 0, 0),retain)
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL5,retain);
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL4,retain);
  SCALE_TO_UINT_init__(&data__->SCALE_TO_UINT0,retain);
  __INIT_VAR(data__->PRESSURE_MAX,3200.00,retain)
  __INIT_VAR(data__->PRESSURE_MIN,0.0,retain)
  __INIT_VAR(data__->POS_MIN,0.0,retain)
  __INIT_VAR(data__->POS_MAX,100.0,retain)
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL0,retain);
  __INIT_VAR(data__->_TMP_SUB53_OUT,0,retain)
  __INIT_VAR(data__->_TMP_LIMIT55_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB57_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL60_OUT,0,retain)
}

// Code part
void PRESSURE_CONTROL_body__(PRESSURE_CONTROL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->SCALE_TO_REAL5.,RAW_INPUT_VALUE,,__GET_VAR(data__->PRESSURE,));
  __SET_VAR(data__->SCALE_TO_REAL5.,REAL_MAX,,__GET_VAR(data__->PRESSURE_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL5.,REAL_MIN,,__GET_VAR(data__->PRESSURE_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL5);
  __SET_VAR(data__->,PRESSURE_REAL,,__GET_VAR(data__->SCALE_TO_REAL5.SCALED_REAL,));
  __SET_VAR(data__->SCALE_TO_REAL4.,RAW_INPUT_VALUE,,__GET_VAR(data__->PRESSURE_SP,));
  __SET_VAR(data__->SCALE_TO_REAL4.,REAL_MAX,,__GET_VAR(data__->PRESSURE_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL4.,REAL_MIN,,__GET_VAR(data__->PRESSURE_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL4);
  __SET_VAR(data__->,PRESSURE_SP_REAL,,__GET_VAR(data__->SCALE_TO_REAL4.SCALED_REAL,));
  __SET_VAR(data__->,_TMP_SUB53_OUT,,SUB__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->VALVE_POS_REAL,),
    (REAL)__GET_VAR(data__->POS_UPDATE_REAL,)));
  __SET_VAR(data__->,_TMP_LIMIT55_OUT,,LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->POS_MIN,),
    (REAL)__GET_VAR(data__->_TMP_SUB53_OUT,),
    (REAL)__GET_VAR(data__->POS_MAX,)));
  __SET_VAR(data__->SCALE_TO_UINT0.,REAL_IN,,__GET_VAR(data__->_TMP_LIMIT55_OUT,));
  SCALE_TO_UINT_body__(&data__->SCALE_TO_UINT0);
  __SET_VAR(data__->,VALVE_POS,,__GET_VAR(data__->SCALE_TO_UINT0.UINT_OUT,));
  __SET_VAR(data__->SCALE_TO_REAL0.,RAW_INPUT_VALUE,,__GET_VAR(data__->CURR_POS,));
  __SET_VAR(data__->SCALE_TO_REAL0.,REAL_MAX,,__GET_VAR(data__->POS_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL0.,REAL_MIN,,__GET_VAR(data__->POS_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL0);
  __SET_VAR(data__->,VALVE_POS_REAL,,__GET_VAR(data__->SCALE_TO_REAL0.SCALED_REAL,));
  __SET_VAR(data__->,_TMP_SUB57_OUT,,SUB__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->PRESSURE_SP_REAL,),
    (REAL)__GET_VAR(data__->PRESSURE_REAL,)));
  __SET_VAR(data__->,_TMP_MUL60_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_SUB57_OUT,),
    (REAL)__GET_VAR(data__->PRESSURE_K,)));
  __SET_VAR(data__->,POS_UPDATE_REAL,,__GET_VAR(data__->_TMP_MUL60_OUT,));

  goto __end;

__end:
  return;
} // PRESSURE_CONTROL_body__() 





void PRESSURE_OVERRIDE_init__(PRESSURE_OVERRIDE *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->PRESSURE_REAL,2700.0,retain)
  __INIT_VAR(data__->PRESSURE,58981,retain)
  __INIT_VAR(data__->CURR_SP,58981,retain)
  __INIT_VAR(data__->CURR_SP_REAL,2700.0,retain)
  __INIT_VAR(data__->PRODUCT_SP_REAL,100.0,retain)
  __INIT_VAR(data__->SP_UPDATE,0.0,retain)
  __INIT_VAR(data__->PRODUCT_SP_NOMINL,100.0,retain)
  __INIT_VAR(data__->PRODUCT_SP,13107,retain)
  __INIT_VAR(data__->OVERRIDE_SP_REAL,2900.0,retain)
  __INIT_VAR(data__->OVERRIDE_SP,63350,retain)
  __INIT_VAR(data__->OVERRIDE_K,1.0,retain)
  __INIT_VAR(data__->OVERRIDE_TI,99999.0,retain)
  __INIT_VAR(data__->CYCLE_TIME,__time_to_timespec(1, 50, 0, 0, 0, 0),retain)
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL7,retain);
  __INIT_VAR(data__->PRESSURE_MAX,3000.0,retain)
  __INIT_VAR(data__->PRESSURE_MIN,0.0,retain)
  __INIT_VAR(data__->FLOW_MAX,500.0,retain)
  __INIT_VAR(data__->FLOW_MIN,0.0,retain)
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL0,retain);
  __INIT_VAR(data__->_TMP_SUB86_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL87_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MAX84_OUT,0,retain)
  __INIT_VAR(data__->_TMP_ADD85_OUT,0,retain)
  __INIT_VAR(data__->_TMP_LIMIT67_OUT,0,retain)
  __INIT_VAR(data__->_TMP_DIV73_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL75_OUT,0,retain)
  __INIT_VAR(data__->_TMP_REAL_TO_UINT79_OUT,0,retain)
}

// Code part
void PRESSURE_OVERRIDE_body__(PRESSURE_OVERRIDE *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_SUB86_OUT,,SUB__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->OVERRIDE_SP_REAL,),
    (REAL)__GET_VAR(data__->PRESSURE_REAL,)));
  __SET_VAR(data__->,_TMP_MUL87_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_SUB86_OUT,),
    (REAL)__GET_VAR(data__->OVERRIDE_K,)));
  __SET_VAR(data__->,_TMP_MAX84_OUT,,MAX__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_MUL87_OUT,),
    (REAL)0.0));
  __SET_VAR(data__->,SP_UPDATE,,__GET_VAR(data__->_TMP_MAX84_OUT,));
  __SET_VAR(data__->SCALE_TO_REAL7.,RAW_INPUT_VALUE,,__GET_VAR(data__->PRESSURE,));
  __SET_VAR(data__->SCALE_TO_REAL7.,REAL_MAX,,__GET_VAR(data__->PRESSURE_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL7.,REAL_MIN,,__GET_VAR(data__->PRESSURE_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL7);
  __SET_VAR(data__->,PRESSURE_REAL,,__GET_VAR(data__->SCALE_TO_REAL7.SCALED_REAL,));
  __SET_VAR(data__->SCALE_TO_REAL0.,RAW_INPUT_VALUE,,__GET_VAR(data__->CURR_SP,));
  __SET_VAR(data__->SCALE_TO_REAL0.,REAL_MAX,,__GET_VAR(data__->FLOW_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL0.,REAL_MIN,,__GET_VAR(data__->FLOW_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL0);
  __SET_VAR(data__->,CURR_SP_REAL,,__GET_VAR(data__->SCALE_TO_REAL0.SCALED_REAL,));
  __SET_VAR(data__->,_TMP_ADD85_OUT,,ADD__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->CURR_SP_REAL,),
    (REAL)__GET_VAR(data__->SP_UPDATE,)));
  __SET_VAR(data__->,_TMP_LIMIT67_OUT,,LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)50.0,
    (REAL)__GET_VAR(data__->_TMP_ADD85_OUT,),
    (REAL)150.0));
  __SET_VAR(data__->,PRODUCT_SP_REAL,,__GET_VAR(data__->_TMP_LIMIT67_OUT,));
  __SET_VAR(data__->,_TMP_DIV73_OUT,,DIV__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->PRODUCT_SP_REAL,),
    (REAL)500.0));
  __SET_VAR(data__->,_TMP_MUL75_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_DIV73_OUT,),
    (REAL)65535.0));
  __SET_VAR(data__->,_TMP_REAL_TO_UINT79_OUT,,REAL_TO_UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->_TMP_MUL75_OUT,)));
  __SET_VAR(data__->,PRODUCT_SP,,__GET_VAR(data__->_TMP_REAL_TO_UINT79_OUT,));

  goto __end;

__end:
  return;
} // PRESSURE_OVERRIDE_body__() 





void LEVEL_CONTROL_init__(LEVEL_CONTROL *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->LIQUID_LEVEL,0,retain)
  __INIT_VAR(data__->LEVEL_SP,30000,retain)
  __INIT_VAR(data__->CURR_POS,0,retain)
  __INIT_VAR(data__->NEW_POS,0,retain)
  __INIT_VAR(data__->CYCLE_TIME,__time_to_timespec(1, 50, 0, 0, 0, 0),retain)
  __INIT_VAR(data__->LEVEL_K,10.0,retain)
  __INIT_VAR(data__->LEVEL_TI,99999.0,retain)
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL0,retain);
  __INIT_VAR(data__->LEVEL_MAX,100.0,retain)
  __INIT_VAR(data__->LEVEL_MIN,0.0,retain)
  __INIT_VAR(data__->POS_MAX,100.0,retain)
  __INIT_VAR(data__->POS_MIN,0.0,retain)
  __INIT_VAR(data__->LEVEL_REAL,44.18,retain)
  __INIT_VAR(data__->POS_REAL,47.0,retain)
  __INIT_VAR(data__->POS_UPDATE_REAL,0.0,retain)
  __INIT_VAR(data__->SP_REAL,44.18,retain)
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL1,retain);
  SCALE_TO_REAL_init__(&data__->SCALE_TO_REAL2,retain);
  SCALE_TO_UINT_init__(&data__->SCALE_TO_UINT0,retain);
  __INIT_VAR(data__->_TMP_SUB32_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MUL33_OUT,0,retain)
  __INIT_VAR(data__->_TMP_SUB30_OUT,0,retain)
  __INIT_VAR(data__->_TMP_LIMIT25_OUT,0,retain)
}

// Code part
void LEVEL_CONTROL_body__(LEVEL_CONTROL *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->SCALE_TO_REAL0.,RAW_INPUT_VALUE,,__GET_VAR(data__->LIQUID_LEVEL,));
  __SET_VAR(data__->SCALE_TO_REAL0.,REAL_MAX,,__GET_VAR(data__->LEVEL_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL0.,REAL_MIN,,__GET_VAR(data__->LEVEL_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL0);
  __SET_VAR(data__->,LEVEL_REAL,,__GET_VAR(data__->SCALE_TO_REAL0.SCALED_REAL,));
  __SET_VAR(data__->SCALE_TO_REAL1.,RAW_INPUT_VALUE,,__GET_VAR(data__->CURR_POS,));
  __SET_VAR(data__->SCALE_TO_REAL1.,REAL_MAX,,__GET_VAR(data__->POS_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL1.,REAL_MIN,,__GET_VAR(data__->POS_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL1);
  __SET_VAR(data__->,POS_REAL,,__GET_VAR(data__->SCALE_TO_REAL1.SCALED_REAL,));
  __SET_VAR(data__->SCALE_TO_REAL2.,RAW_INPUT_VALUE,,__GET_VAR(data__->LEVEL_SP,));
  __SET_VAR(data__->SCALE_TO_REAL2.,REAL_MAX,,__GET_VAR(data__->LEVEL_MAX,));
  __SET_VAR(data__->SCALE_TO_REAL2.,REAL_MIN,,__GET_VAR(data__->LEVEL_MIN,));
  SCALE_TO_REAL_body__(&data__->SCALE_TO_REAL2);
  __SET_VAR(data__->,SP_REAL,,__GET_VAR(data__->SCALE_TO_REAL2.SCALED_REAL,));
  __SET_VAR(data__->,_TMP_SUB32_OUT,,SUB__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->SP_REAL,),
    (REAL)__GET_VAR(data__->LEVEL_REAL,)));
  __SET_VAR(data__->,_TMP_MUL33_OUT,,MUL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (REAL)__GET_VAR(data__->_TMP_SUB32_OUT,),
    (REAL)__GET_VAR(data__->LEVEL_K,)));
  __SET_VAR(data__->,POS_UPDATE_REAL,,__GET_VAR(data__->_TMP_MUL33_OUT,));
  __SET_VAR(data__->,_TMP_SUB30_OUT,,SUB__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->POS_REAL,),
    (REAL)__GET_VAR(data__->POS_UPDATE_REAL,)));
  __SET_VAR(data__->,_TMP_LIMIT25_OUT,,LIMIT__REAL__REAL__REAL__REAL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (REAL)__GET_VAR(data__->POS_MIN,),
    (REAL)__GET_VAR(data__->_TMP_SUB30_OUT,),
    (REAL)__GET_VAR(data__->POS_MAX,)));
  __SET_VAR(data__->SCALE_TO_UINT0.,REAL_IN,,__GET_VAR(data__->_TMP_LIMIT25_OUT,));
  SCALE_TO_UINT_body__(&data__->SCALE_TO_UINT0);
  __SET_VAR(data__->,NEW_POS,,__GET_VAR(data__->SCALE_TO_UINT0.UINT_OUT,));

  goto __end;

__end:
  return;
} // LEVEL_CONTROL_body__() 





void INITIALIZE_SP_init__(INITIALIZE_SP *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->FLOW_SP_C,19660,retain)
  __INIT_VAR(data__->A_SP_C,30801,retain)
  __INIT_VAR(data__->PRESS_SP_C,55295,retain)
  __INIT_VAR(data__->OVER_SP_C,31675,retain)
  __INIT_VAR(data__->LEVEL_SP_C,28835,retain)
  __INIT_VAR(data__->FLOW_SP,0,retain)
  __INIT_VAR(data__->A_SP,0,retain)
  __INIT_VAR(data__->PRESS_SP,0,retain)
  __INIT_VAR(data__->OVER_SP,0,retain)
  __INIT_VAR(data__->LEVEL_SP,0,retain)
  __INIT_VAR(data__->_TMP_MOVE3_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE7_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE11_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE15_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE19_OUT,0,retain)
}

// Code part
void INITIALIZE_SP_body__(INITIALIZE_SP *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  __SET_VAR(data__->,_TMP_MOVE3_OUT,,MOVE__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->A_SP_C,)));
  __SET_VAR(data__->,A_SP,,__GET_VAR(data__->_TMP_MOVE3_OUT,));
  __SET_VAR(data__->,_TMP_MOVE7_OUT,,MOVE__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->FLOW_SP_C,)));
  __SET_VAR(data__->,FLOW_SP,,__GET_VAR(data__->_TMP_MOVE7_OUT,));
  __SET_VAR(data__->,_TMP_MOVE11_OUT,,MOVE__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->OVER_SP_C,)));
  __SET_VAR(data__->,OVER_SP,,__GET_VAR(data__->_TMP_MOVE11_OUT,));
  __SET_VAR(data__->,_TMP_MOVE15_OUT,,MOVE__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->LEVEL_SP_C,)));
  __SET_VAR(data__->,LEVEL_SP,,__GET_VAR(data__->_TMP_MOVE15_OUT,));
  __SET_VAR(data__->,_TMP_MOVE19_OUT,,MOVE__UINT__UINT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)__GET_VAR(data__->PRESS_SP_C,)));
  __SET_VAR(data__->,PRESS_SP,,__GET_VAR(data__->_TMP_MOVE19_OUT,));

  goto __end;

__end:
  return;
} // INITIALIZE_SP_body__() 





static inline UINT __MAIN_MOVE__UINT__UINT1(BOOL EN,
  UINT IN,
  MAIN *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE99_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE99_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MAIN_MOVE__UINT__UINT2(BOOL EN,
  UINT IN,
  MAIN *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE4_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE4_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MAIN_MOVE__UINT__UINT3(BOOL EN,
  UINT IN,
  MAIN *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE5_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE5_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MAIN_MOVE__UINT__UINT4(BOOL EN,
  UINT IN,
  MAIN *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE7_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE7_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MAIN_MOVE__UINT__UINT5(BOOL EN,
  UINT IN,
  MAIN *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE13_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE13_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MAIN_MOVE__UINT__UINT6(BOOL EN,
  UINT IN,
  MAIN *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE20_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE20_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MAIN_MOVE__UINT__UINT7(BOOL EN,
  UINT IN,
  MAIN *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE19_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE19_ENO,,__TMP_ENO);
  return __res;
}

static inline UINT __MAIN_MOVE__UINT__UINT8(BOOL EN,
  UINT IN,
  MAIN *data__)
{
  UINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->_TMP_MOVE25_ENO,);
  __res = MOVE__UINT__UINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->_TMP_MOVE25_ENO,,__TMP_ENO);
  return __res;
}

void MAIN_init__(MAIN *data__, BOOL retain) {
  FLOW_CONTROL_init__(&data__->FLOW_CONTROL0,retain);
  __INIT_LOCATED(BOOL,__QX0_7,data__->FIRST_RUN,retain)
  __INIT_LOCATED_VALUE(data__->FIRST_RUN,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(UINT,__MW1,data__->FLOW_SET,retain)
  __INIT_LOCATED_VALUE(data__->FLOW_SET,0)
  __INIT_LOCATED(UINT,__MW2,data__->A_SETPOINT,retain)
  __INIT_LOCATED_VALUE(data__->A_SETPOINT,0)
  __INIT_LOCATED(UINT,__MW3,data__->PRESSURE_SP,retain)
  __INIT_LOCATED_VALUE(data__->PRESSURE_SP,0)
  __INIT_LOCATED(UINT,__MW4,data__->OVERRIDE_SP,retain)
  __INIT_LOCATED_VALUE(data__->OVERRIDE_SP,0)
  __INIT_LOCATED(UINT,__MW5,data__->LEVEL_SP,retain)
  __INIT_LOCATED_VALUE(data__->LEVEL_SP,0)
  COMPOSITION_CONTROL_init__(&data__->COMPOSITION_CONTROL0,retain);
  __INIT_LOCATED(UINT,__IW100,data__->F1_VALVE_POS,retain)
  __INIT_LOCATED_VALUE(data__->F1_VALVE_POS,0)
  __INIT_LOCATED(UINT,__IW101,data__->F1_FLOW,retain)
  __INIT_LOCATED_VALUE(data__->F1_FLOW,0)
  __INIT_LOCATED(UINT,__IW102,data__->F2_VALVE_POS,retain)
  __INIT_LOCATED_VALUE(data__->F2_VALVE_POS,0)
  __INIT_LOCATED(UINT,__IW103,data__->F2_FLOW,retain)
  __INIT_LOCATED_VALUE(data__->F2_FLOW,0)
  __INIT_LOCATED(UINT,__IW104,data__->PURGE_VALVE_POS,retain)
  __INIT_LOCATED_VALUE(data__->PURGE_VALVE_POS,0)
  __INIT_LOCATED(UINT,__IW105,data__->PURGE_FLOW,retain)
  __INIT_LOCATED_VALUE(data__->PURGE_FLOW,0)
  __INIT_LOCATED(UINT,__IW106,data__->PRODUCT_VALVE_POS,retain)
  __INIT_LOCATED_VALUE(data__->PRODUCT_VALVE_POS,0)
  __INIT_LOCATED(UINT,__IW107,data__->PRODUCT_FLOW,retain)
  __INIT_LOCATED_VALUE(data__->PRODUCT_FLOW,0)
  __INIT_LOCATED(UINT,__IW108,data__->PRESSURE,retain)
  __INIT_LOCATED_VALUE(data__->PRESSURE,0)
  __INIT_LOCATED(UINT,__IW109,data__->LEVEL,retain)
  __INIT_LOCATED_VALUE(data__->LEVEL,0)
  __INIT_LOCATED(UINT,__IW110,data__->A_IN_PURGE,retain)
  __INIT_LOCATED_VALUE(data__->A_IN_PURGE,0)
  __INIT_LOCATED(UINT,__IW111,data__->B_IN_PURGE,retain)
  __INIT_LOCATED_VALUE(data__->B_IN_PURGE,0)
  __INIT_LOCATED(UINT,__IW112,data__->C_IN_PURGE,retain)
  __INIT_LOCATED_VALUE(data__->C_IN_PURGE,0)
  __INIT_LOCATED(UINT,__QW100,data__->F1_VALVE_SP,retain)
  __INIT_LOCATED_VALUE(data__->F1_VALVE_SP,0)
  __INIT_LOCATED(UINT,__QW101,data__->F2_VALVE_SP,retain)
  __INIT_LOCATED_VALUE(data__->F2_VALVE_SP,0)
  __INIT_LOCATED(UINT,__QW102,data__->PURGE_VALVE_SP,retain)
  __INIT_LOCATED_VALUE(data__->PURGE_VALVE_SP,0)
  __INIT_LOCATED(UINT,__QW103,data__->PRODUCT_VALVE_SP,retain)
  __INIT_LOCATED_VALUE(data__->PRODUCT_VALVE_SP,0)
  __INIT_VAR(data__->PRODUCT_VALVE_SAFE,0,retain)
  __INIT_VAR(data__->PURGE_VALVE_SAFE,65535,retain)
  __INIT_VAR(data__->F1_VALVE_SAFE,0,retain)
  __INIT_VAR(data__->F2_VALVE_SAFE,0,retain)
  PRESSURE_CONTROL_init__(&data__->PRESSURE_CONTROL0,retain);
  __INIT_LOCATED(INT,__MW20,data__->HMI_PRESSURE,retain)
  __INIT_LOCATED_VALUE(data__->HMI_PRESSURE,0)
  __INIT_LOCATED(INT,__MW21,data__->HMI_LEVEL,retain)
  __INIT_LOCATED_VALUE(data__->HMI_LEVEL,0)
  __INIT_LOCATED(INT,__MW22,data__->HMI_F1_VALVE_POS,retain)
  __INIT_LOCATED_VALUE(data__->HMI_F1_VALVE_POS,0)
  __INIT_LOCATED(INT,__MW23,data__->HMI_F1_FLOW,retain)
  __INIT_LOCATED_VALUE(data__->HMI_F1_FLOW,0)
  __INIT_LOCATED(INT,__MW24,data__->HMI_F2_VALVE_POS,retain)
  __INIT_LOCATED_VALUE(data__->HMI_F2_VALVE_POS,0)
  __INIT_LOCATED(INT,__MW25,data__->HMI_F2_FLOW,retain)
  __INIT_LOCATED_VALUE(data__->HMI_F2_FLOW,0)
  __INIT_LOCATED(INT,__MW26,data__->HMI_PURGE_VALVE_POS,retain)
  __INIT_LOCATED_VALUE(data__->HMI_PURGE_VALVE_POS,0)
  __INIT_LOCATED(INT,__MW27,data__->HMI_PURGE_FLOW,retain)
  __INIT_LOCATED_VALUE(data__->HMI_PURGE_FLOW,0)
  __INIT_LOCATED(INT,__MW28,data__->HMI_PRODUCT_VALVE_POS,retain)
  __INIT_LOCATED_VALUE(data__->HMI_PRODUCT_VALVE_POS,0)
  __INIT_LOCATED(INT,__MW29,data__->HMI_PRODUCT_FLOW,retain)
  __INIT_LOCATED_VALUE(data__->HMI_PRODUCT_FLOW,0)
  __INIT_LOCATED(UINT,__MW30,data__->SCAN_COUNT,retain)
  __INIT_LOCATED_VALUE(data__->SCAN_COUNT,0)
  PRESSURE_OVERRIDE_init__(&data__->PRESSURE_OVERRIDE0,retain);
  LEVEL_CONTROL_init__(&data__->LEVEL_CONTROL0,retain);
  __INIT_LOCATED(BOOL,__QX0_5,data__->RUN_BIT,retain)
  __INIT_LOCATED_VALUE(data__->RUN_BIT,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_6,data__->ATTACK,retain)
  __INIT_LOCATED_VALUE(data__->ATTACK,__BOOL_LITERAL(FALSE))
  INITIALIZE_SP_init__(&data__->INITIALIZE_SP0,retain);
  __INIT_VAR(data__->_TMP_MOVE99_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE99_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE4_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE4_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE5_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE5_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE7_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE7_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE13_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE13_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE20_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE20_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE19_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE19_OUT,0,retain)
  __INIT_VAR(data__->_TMP_MOVE25_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_MOVE25_OUT,0,retain)
}

// Code part
void MAIN_body__(MAIN *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->FLOW_CONTROL0.,PRODUCT_FLOW,,__GET_LOCATED(data__->PRODUCT_FLOW,));
  __SET_VAR(data__->FLOW_CONTROL0.,CURR_POS,,__GET_LOCATED(data__->F1_VALVE_POS,));
  __SET_VAR(data__->FLOW_CONTROL0.,FLOW_SET_IN,,__GET_LOCATED(data__->FLOW_SET,));
  FLOW_CONTROL_body__(&data__->FLOW_CONTROL0);
  __SET_LOCATED(data__->,F1_VALVE_SP,,__GET_VAR(data__->FLOW_CONTROL0.NEW_POS,));
  __SET_VAR(data__->COMPOSITION_CONTROL0.,A_IN_PURGE,,__GET_LOCATED(data__->A_IN_PURGE,));
  __SET_VAR(data__->COMPOSITION_CONTROL0.,A_SETPOINT,,__GET_LOCATED(data__->A_SETPOINT,));
  __SET_VAR(data__->COMPOSITION_CONTROL0.,CURR_POS,,__GET_LOCATED(data__->F2_VALVE_POS,));
  COMPOSITION_CONTROL_body__(&data__->COMPOSITION_CONTROL0);
  __SET_LOCATED(data__->,F2_VALVE_SP,,__GET_VAR(data__->COMPOSITION_CONTROL0.NEW_POS,));
  __SET_VAR(data__->PRESSURE_CONTROL0.,PRESSURE,,__GET_LOCATED(data__->PRESSURE,));
  __SET_VAR(data__->PRESSURE_CONTROL0.,PRESSURE_SP,,__GET_LOCATED(data__->PRESSURE_SP,));
  __SET_VAR(data__->PRESSURE_CONTROL0.,CURR_POS,,__GET_LOCATED(data__->PURGE_VALVE_POS,));
  PRESSURE_CONTROL_body__(&data__->PRESSURE_CONTROL0);
  __SET_LOCATED(data__->,PURGE_VALVE_SP,,__GET_VAR(data__->PRESSURE_CONTROL0.VALVE_POS,));
  __SET_VAR(data__->PRESSURE_OVERRIDE0.,PRESSURE,,__GET_LOCATED(data__->PRESSURE,));
  __SET_VAR(data__->PRESSURE_OVERRIDE0.,CURR_SP,,__GET_LOCATED(data__->FLOW_SET,));
  __SET_VAR(data__->PRESSURE_OVERRIDE0.,OVERRIDE_SP,,__GET_LOCATED(data__->OVERRIDE_SP,));
  PRESSURE_OVERRIDE_body__(&data__->PRESSURE_OVERRIDE0);
  __SET_LOCATED(data__->,FLOW_SET,,__GET_VAR(data__->PRESSURE_OVERRIDE0.PRODUCT_SP,));
  __SET_VAR(data__->LEVEL_CONTROL0.,LIQUID_LEVEL,,__GET_LOCATED(data__->LEVEL,));
  __SET_VAR(data__->LEVEL_CONTROL0.,LEVEL_SP,,__GET_LOCATED(data__->LEVEL_SP,));
  __SET_VAR(data__->LEVEL_CONTROL0.,CURR_POS,,__GET_LOCATED(data__->PRODUCT_VALVE_POS,));
  LEVEL_CONTROL_body__(&data__->LEVEL_CONTROL0);
  __SET_LOCATED(data__->,PRODUCT_VALVE_SP,,__GET_VAR(data__->LEVEL_CONTROL0.NEW_POS,));
  __SET_VAR(data__->INITIALIZE_SP0.,EN,,__GET_LOCATED(data__->FIRST_RUN,));
  INITIALIZE_SP_body__(&data__->INITIALIZE_SP0);
  if (__GET_VAR(data__->INITIALIZE_SP0.ENO,)) {
    __SET_LOCATED(data__->,FIRST_RUN,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->INITIALIZE_SP0.ENO,)) {
    __SET_LOCATED(data__->,A_SETPOINT,,__GET_VAR(data__->INITIALIZE_SP0.A_SP,));
  };
  if (__GET_VAR(data__->INITIALIZE_SP0.ENO,)) {
    __SET_LOCATED(data__->,FLOW_SET,,__GET_VAR(data__->INITIALIZE_SP0.FLOW_SP,));
  };
  if (__GET_VAR(data__->INITIALIZE_SP0.ENO,)) {
    __SET_LOCATED(data__->,PRESSURE_SP,,__GET_VAR(data__->INITIALIZE_SP0.PRESS_SP,));
  };
  if (__GET_VAR(data__->INITIALIZE_SP0.ENO,)) {
    __SET_LOCATED(data__->,OVERRIDE_SP,,__GET_VAR(data__->INITIALIZE_SP0.OVER_SP,));
  };
  if (__GET_VAR(data__->INITIALIZE_SP0.ENO,)) {
    __SET_LOCATED(data__->,LEVEL_SP,,__GET_VAR(data__->INITIALIZE_SP0.LEVEL_SP,));
  };
  __SET_VAR(data__->,_TMP_MOVE99_OUT,,__MAIN_MOVE__UINT__UINT1(
    (BOOL)__GET_LOCATED(data__->RUN_BIT,),
    (UINT)0,
    data__));
  __SET_VAR(data__->,_TMP_MOVE4_OUT,,__MAIN_MOVE__UINT__UINT2(
    (BOOL)__GET_VAR(data__->_TMP_MOVE99_ENO,),
    (UINT)0,
    data__));
  __SET_VAR(data__->,_TMP_MOVE5_OUT,,__MAIN_MOVE__UINT__UINT3(
    (BOOL)__GET_VAR(data__->_TMP_MOVE4_ENO,),
    (UINT)65535,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE5_ENO,)) {
    __SET_LOCATED(data__->,PURGE_VALVE_SP,,__GET_VAR(data__->_TMP_MOVE5_OUT,));
  };
  __SET_VAR(data__->,_TMP_MOVE7_OUT,,__MAIN_MOVE__UINT__UINT4(
    (BOOL)__GET_VAR(data__->_TMP_MOVE5_ENO,),
    (UINT)65535,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE7_ENO,)) {
    __SET_LOCATED(data__->,PRODUCT_VALVE_SP,,__GET_VAR(data__->_TMP_MOVE7_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE99_ENO,)) {
    __SET_LOCATED(data__->,F1_VALVE_SP,,__GET_VAR(data__->_TMP_MOVE99_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE4_ENO,)) {
    __SET_LOCATED(data__->,F2_VALVE_SP,,__GET_VAR(data__->_TMP_MOVE4_OUT,));
  };
  __SET_VAR(data__->,_TMP_MOVE13_OUT,,__MAIN_MOVE__UINT__UINT5(
    (BOOL)__GET_LOCATED(data__->ATTACK,),
    (UINT)65535,
    data__));
  __SET_VAR(data__->,_TMP_MOVE20_OUT,,__MAIN_MOVE__UINT__UINT6(
    (BOOL)__GET_VAR(data__->_TMP_MOVE13_ENO,),
    (UINT)65535,
    data__));
  __SET_VAR(data__->,_TMP_MOVE19_OUT,,__MAIN_MOVE__UINT__UINT7(
    (BOOL)__GET_VAR(data__->_TMP_MOVE20_ENO,),
    (UINT)0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE19_ENO,)) {
    __SET_LOCATED(data__->,PURGE_VALVE_SP,,__GET_VAR(data__->_TMP_MOVE19_OUT,));
  };
  __SET_VAR(data__->,_TMP_MOVE25_OUT,,__MAIN_MOVE__UINT__UINT8(
    (BOOL)__GET_VAR(data__->_TMP_MOVE19_ENO,),
    (UINT)0,
    data__));
  if (__GET_VAR(data__->_TMP_MOVE25_ENO,)) {
    __SET_LOCATED(data__->,PRODUCT_VALVE_SP,,__GET_VAR(data__->_TMP_MOVE25_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE13_ENO,)) {
    __SET_LOCATED(data__->,F1_VALVE_SP,,__GET_VAR(data__->_TMP_MOVE13_OUT,));
  };
  if (__GET_VAR(data__->_TMP_MOVE20_ENO,)) {
    __SET_LOCATED(data__->,F2_VALVE_SP,,__GET_VAR(data__->_TMP_MOVE20_OUT,));
  };

  goto __end;

__end:
  return;
} // MAIN_body__() 





