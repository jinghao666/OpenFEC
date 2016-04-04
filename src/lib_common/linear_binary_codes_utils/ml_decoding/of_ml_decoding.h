/* $Id: of_ml_decoding.h 72 2012-04-13 13:27:26Z detchart $ */
/*
 * OpenFEC.org AL-FEC Library.
 * (c) Copyright 2009 - 2012 INRIA - All rights reserved
 * Contact: vincent.roca@inria.fr
 *
 * This software is governed by the CeCILL-C license under French law and
 * abiding by the rules of distribution of free software.  You can  use,
 * modify and/ or redistribute the software under the terms of the CeCILL-C
 * license as circulated by CEA, CNRS and INRIA at the following URL
 * "http://www.cecill.info".
 *
 * As a counterpart to the access to the source code and  rights to copy,
 * modify and redistribute granted by the license, users are provided only
 * with a limited warranty  and the software's author,  the holder of the
 * economic rights,  and the successive licensors  have only  limited
 * liability.
 *
 * In this respect, the user's attention is drawn to the risks associated
 * with loading,  using,  modifying and/or developing or reproducing the
 * software by the user in light of its specific status of free software,
 * that may mean  that it is complicated to manipulate,  and  that  also
 * therefore means  that it is reserved for developers  and  experienced
 * professionals having in-depth computer knowledge. Users are therefore
 * encouraged to load and test the software's suitability as regards their
 * requirements in conditions enabling the security of their systems and/or
 * data to be ensured and,  more generally, to use and operate it in the
 * same conditions as regards security.
 *
 * The fact that you are presently reading this means that you have had
 * knowledge of the CeCILL-C license and that you accept its terms.
 */

#ifndef ML_DECODING_H
#define ML_DECODING_H

#include "../../of_openfec_api.h"

#ifdef OF_USE_DECODER
#ifdef OF_USE_LINEAR_BINARY_CODES_UTILS
#ifdef ML_DECODING

#include "../of_linear_binary_code.h"
#include "of_ml_tool.h"
#include "of_ml_tool_2.h"
#include <stdio.h>
/**
 * This function simplifies the linear system (H): delete rows and cols when we can.
 *
 * @fn of_status_t		of_linear_binary_code_simplify_linear_system (of_linear_binary_code_cb_t *ofcb,const void* new_symbol,UINT32 new_symbol_esi)
 * @brief			symplify the linear system
 * @param ofcb 			(IN/OUT) Linear-Binary-Code control-block.
 * @param new_symbol		(IN/OUT) pointer to new symbol to process
 * @param new_symbol_esi	(IN) Encoding Symbol Index
 * @return			1 if it's OK, or 0 if an error appears.
 */
of_status_t of_linear_binary_code_simplify_linear_system   (of_linear_binary_code_cb_t* ofcb,
							const void* new_symbol,
							UINT32 new_symbol_esi);

/**
 * This function tries to finish decoding.
 *
 * @fn of_status_t		of_linear_binary_code_finish_decoding_with_ml (of_linear_binary_code_cb_t *ofcb)
 * @brief			try to finish decoding
 * @param ofcb 			(IN/OUT) Linear-Binary-Code control-block.
 * @return			1 if it's OK, or 0 if an error appears.
 */
of_status_t of_linear_binary_code_finish_decoding_with_ml (of_linear_binary_code_cb_t *ofcb);

/**
 * This function tries to finish decoding on a parity check matrix.
 *
 * @fn of_status_t		of_ldpc_staircase_finish_decoding_with_ml (of_linear_binary_code_cb_t *ofcb)
 * @brief			try to finish decoding
 * @param ofcb 			(IN/OUT) Linear-Binary-Code control-block.
 * @return			1 if it's OK, or 0 if an error appears.
 */
of_status_t of_linear_binary_code_finish_with_ml_decoding_on_parity_check_matrix (of_linear_binary_code_cb_t *ofcb);

#endif //ML_DECODING

#endif //OF_USE_LINEAR_BINARY_CODES_UTILS

#endif //OF_USE_DECODER

#endif /* ML_DECODING_H */
