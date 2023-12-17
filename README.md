
### AUTHOR: XAVIER NOUNDOU (yerith.d at gmail.com).


COMMERCIAL CASE (Computer-Aided Software Engineering) tool
to draw, generate text files ([YRI_QVGE (https://zenodo.org/record/8045734/)](https://zenodo.org/record/8045734/)).

![YRI_QVGE CASE (Computer-Aided Software Engineering) tool](https://github.com/yerithd/yri_sd_runtime_verif_lang/blob/master/YRI_QVGE_screenshot.png?raw=true)


### MIT SOFTWARE LICENSED


### HOW TO BUILD THIS PROJECT

Run bash script '**build_yri_sd_runtime_verig_lang.sh**'.


### HOW TO GENERATE C++ FILES for 'yr-db-runtime-verif' FROM A SPECIFICATION FILE

[yr-db-runtime-verif: a project for verifying SQL correctness properties of GUI software at runtime](https://github.com/yerithd/yr-db-runtime-verif)

./yri_sd_runtime_verif_lang_comp < yri_sd_runtime_verif.sd_mealy


### HERE is a sample state diagram mealy machine SPECIFICATION

![yri_test_input_2](test_inputs/yri_test_input_2.png)

yri_sd_mealy_automaton_spec yri_MISSING_department<br />
{<br />
 &nbsp;&nbsp;START_STATE(D):Q0<br />
 &nbsp;&nbsp;&nbsp;&nbsp;-> / 'select.department' -><br />
 &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ERROR_STATE(E):Q1.<br />
}

