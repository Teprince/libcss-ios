//
//  flex_basis.c
//  libcss
//
//  Created by Teprince on 7/23/16.
//  Copyright © 2016 Teprince. All rights reserved.
//

#include "bytecode/bytecode.h"
#include "bytecode/opcodes.h"
#include "select/propset.h"
#include "select/propget.h"
#include "utils/utils.h"

#include "select/properties/properties.h"
#include "select/properties/helpers.h"

css_error css__cascade_flex_basis(uint32_t opv, css_style *style,
                                  css_select_state *state)
{
    uint16_t value = CSS_FLEX_BASIS_INHERIT;
    css_fixed index = 0;
    
    if (isInherit(opv) == false) {
        switch (getValue(opv)) {
            case FLEX_BASIS_SET:
                value = CSS_FLEX_BASIS_SET;
                
                index = *((css_fixed *) style->bytecode);
                advance_bytecode(style, sizeof(index));
                break;
            case FLEX_BASIS_AUTO:
                value = CSS_FLEX_BASIS_AUTO;
                break;
        }
    }
    
    if (css__outranks_existing(getOpcode(opv), isImportant(opv), state,
                               isInherit(opv))) {
        /** \todo set computed elevation */
    }
    
    return CSS_OK;
}

css_error css__set_flex_basis_from_hint(const css_hint *hint,
                                        css_computed_style *style)
{
    UNUSED(hint);
    UNUSED(style);
    
    return CSS_OK;
}

css_error css__initial_flex_basis(css_select_state *state)
{
    UNUSED(state);
    
    return CSS_OK;
}

css_error css__compose_flex_basis(const css_computed_style *parent,
                                  const css_computed_style *child,
                                  css_computed_style *result)
{
    UNUSED(parent);
    UNUSED(child);
    UNUSED(result);
    
    return CSS_OK;
}

