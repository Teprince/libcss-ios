//
//  flex_direction.c
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

css_error css__cascade_flex_direction(uint32_t opv, css_style *style,
                                      css_select_state *state)
{
    uint16_t value = CSS_FLEX_DIRECTION_INHERIT;
    
    UNUSED(style);
    
    if (isInherit(opv) == false) {
        switch (getValue(opv)) {
            case FLEX_DIRECTION_COLUMN:
                value = CSS_FLEX_DIRECTION_COLUMN;
                break;
            case FLEX_DIRECTION_COLUMN_REVERSE:
                value = CSS_FLEX_DIRECTION_COLUMN_REVERSE;
                break;
            case FLEX_DIRECTION_ROW:
                value = CSS_FLEX_DIRECTION_ROW;
                break;
            case FLEX_DIRECTION_ROW_REVERSE:
                value = CSS_FLEX_DIRECTION_ROW_REVERSE;
                break;
        }
    }
    
    if (css__outranks_existing(getOpcode(opv), isImportant(opv), state,
                               isInherit(opv))) {
        /** \todo set computed elevation */
    }
    
    return CSS_OK;
}

css_error css__set_flex_direction_from_hint(const css_hint *hint,
                                            css_computed_style *style)
{
    UNUSED(hint);
    UNUSED(style);
    
    return CSS_OK;
}

css_error css__initial_flex_direction(css_select_state *state)
{
    UNUSED(state);
    
    return CSS_OK;
}

css_error css__compose_flex_direction(const css_computed_style *parent,
                                      const css_computed_style *child,
                                      css_computed_style *result)
{
    UNUSED(parent);
    UNUSED(child);
    UNUSED(result);
    
    return CSS_OK;
}

