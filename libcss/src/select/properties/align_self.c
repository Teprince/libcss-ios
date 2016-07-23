//
//  align_self.c
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

css_error css__cascade_align_self(uint32_t opv, css_style *style,
                                  css_select_state *state)
{
    uint16_t value = CSS_ALIGN_SELF_INHERIT;
    
    UNUSED(style);

    if (isInherit(opv) == false) {
        switch (getValue(opv)) {
            case ALIGN_SELF_AUTO:
                value = CSS_ALIGN_SELF_AUTO;
                break;
            case ALIGN_SELF_FLEX_START:
                value = CSS_ALIGN_SELF_FLEX_START;
                break;
            case ALIGN_SELF_CENTER:
                value = CSS_ALIGN_SELF_CENTER;
                break;
            case ALIGN_SELF_FLEX_END:
                value = CSS_ALIGN_SELF_FLEX_END;
                break;
            case ALIGN_SELF_STRETCH:
                value = CSS_ALIGN_SELF_STRETCH;
                break;
            case ALIGN_SELF_BASELINE:
                value = CSS_ALIGN_SELF_BASELINE;
                break;
        }
    }
    
    if (css__outranks_existing(getOpcode(opv), isImportant(opv), state,
                               isInherit(opv))) {
        /** \todo set computed elevation */
    }
    
    return CSS_OK;
}

css_error css__set_align_self_from_hint(const css_hint *hint,
                                        css_computed_style *style)
{
    UNUSED(hint);
    UNUSED(style);
    
    return CSS_OK;
}

css_error css__initial_align_self(css_select_state *state)
{
    UNUSED(state);
    
    return CSS_OK;
}

css_error css__compose_align_self(const css_computed_style *parent,
                                  const css_computed_style *child,
                                  css_computed_style *result)
{
    UNUSED(parent);
    UNUSED(child);
    UNUSED(result);
    
    return CSS_OK;
}
