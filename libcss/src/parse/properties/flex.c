//
//  flex.c
//  libcss
//
//  Created by HuGuanqin on 7/24/16.
//  Copyright © 2016 Teprince. All rights reserved.
//

#include <assert.h>
#include <string.h>

#include "bytecode/bytecode.h"
#include "bytecode/opcodes.h"
#include "parse/properties/properties.h"
#include "parse/properties/utils.h"

/**
 * Parse flex ShortHand ---- facebook css layout, not css3 spec
 *
 * \param c	  Parsing context
 * \param vector  Vector of tokens to process
 * \param ctx	  Pointer to vector iteration context
 * \param result  resulting style
 * \return CSS_OK on success,
 *	   CSS_NOMEM on memory exhaustion,
 *	   CSS_INVALID if the input is not valid
 *
 * Post condition: \a *ctx is updated with the next token to process
 *		   If the input is invalid, then \a *ctx remains unchanged.
 */
css_error css__parse_flex(css_language *c,
                          const parserutils_vector *vector, int *ctx,
                          css_style *result)
{
    int orig_ctx = *ctx;
    css_error error;
    const css_token *token;
    
    token = parserutils_vector_iterate(vector, ctx);
    if ((token == NULL) || (token->type != CSS_TOKEN_NUMBER)) {
        *ctx = orig_ctx;
        return CSS_INVALID;
    }
    
    if (token->type == CSS_TOKEN_NUMBER) {
        css_fixed num = 0;
        size_t consumed = 0;
        
        num = css__number_from_lwc_string(token->idata, true, &consumed);
        /* Invalid if there are trailing characters */
        if (consumed != lwc_string_length(token->idata)) {
            *ctx = orig_ctx;
            return CSS_INVALID;
        }
        
        error = CSS_OK;
        
        if (num > 0)
        {
            error = css__stylesheet_style_appendOPV(result, CSS_PROP_FLEX_GROW, 0, FLEX_GROW_SET);
            if (error != CSS_OK) {
                *ctx = orig_ctx;
                return error;
            }
            
            error = css__stylesheet_style_append(result, num);
            if (error != CSS_OK) {
                *ctx = orig_ctx;
                return error;
            }
            
            error = css__stylesheet_style_appendOPV(result, CSS_PROP_FLEX_BASIS, 0, FLEX_BASIS_SET);
            if (error != CSS_OK) {
                *ctx = orig_ctx;
                return error;
            }
            
            error = css__stylesheet_style_append(result, 0);
        }
        else if ((num >> 10) == -1)
        {
            error = css__stylesheet_style_appendOPV(result, CSS_PROP_FLEX_SHRINK, 0, FLEX_SHRINK_SET);
            if (error != CSS_OK) {
                *ctx = orig_ctx;
                return error;
            }
            
            error = css__stylesheet_style_append(result, 1 << 10);
        }
    } else {
        error = CSS_INVALID;
    }
    
    if (error != CSS_OK)
        *ctx = orig_ctx;
    
    return error;
}
