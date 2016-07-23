//
//  flex_wrap.c
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

css_error css__cascade_flex_wrap(uint32_t opv, css_style *style,
                                      css_select_state *state)
{
    uint16_t value = CSS_FLEX_WRAP_INHERIT;
    
    UNUSED(style);

    if (isInherit(opv) == false) {
        switch (getValue(opv)) {
            case FLEX_WRAP_NOWRAP:
                value = CSS_FLEX_WRAP_NOWRAP;
                break;
            case FLEX_WRAP_WRAP:
                value = CSS_FLEX_WRAP_WRAP;
                break;
            case FLEX_WRAP_REVERSE:
                value = CSS_FLEX_WRAP_REVERSE;
                break;
        }
    }
    
    if (css__outranks_existing(getOpcode(opv), isImportant(opv), state,
                               isInherit(opv))) {
        /** \todo set computed elevation */
    }
    
    return CSS_OK;
}

css_error css__set_flex_wrap_from_hint(const css_hint *hint,
                                            css_computed_style *style)
{
    UNUSED(hint);
    UNUSED(style);
    
    return CSS_OK;
}

css_error css__initial_flex_wrap(css_select_state *state)
{
    UNUSED(state);
    
    return CSS_OK;
}

css_error css__compose_flex_wrap(const css_computed_style *parent,
                                      const css_computed_style *child,
                                      css_computed_style *result)
{
    UNUSED(parent);
    UNUSED(child);
    UNUSED(result);
    
    return CSS_OK;
}
