// This file was autogenerated by some hot garbage in the `uniffi` crate.
// Trust me, you don't want to mess with it!

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// The following structs are used to implement the lowest level
// of the FFI, and thus useful to multiple uniffied crates.
// We ensure they are declared exactly once, with a header guard, UNIFFI_SHARED_H.
#ifdef UNIFFI_SHARED_H
    // We also try to prevent mixing versions of shared uniffi header structs.
    // If you add anything to the #else block, you must increment the version suffix in UNIFFI_SHARED_HEADER_V4
    #ifndef UNIFFI_SHARED_HEADER_V4
        #error Combining helper code from multiple versions of uniffi is not supported
    #endif // ndef UNIFFI_SHARED_HEADER_V4
#else
#define UNIFFI_SHARED_H
#define UNIFFI_SHARED_HEADER_V4
// ⚠️ Attention: If you change this #else block (ending in `#endif // def UNIFFI_SHARED_H`) you *must* ⚠️
// ⚠️ increment the version suffix in all instances of UNIFFI_SHARED_HEADER_V4 in this file.           ⚠️

typedef struct RustBuffer
{
    int32_t capacity;
    int32_t len;
    uint8_t *_Nullable data;
} RustBuffer;

typedef int32_t (*ForeignCallback)(uint64_t, int32_t, const uint8_t *_Nonnull, int32_t, RustBuffer *_Nonnull);

// Task defined in Rust that Swift executes
typedef void (*UniFfiRustTaskCallback)(const void * _Nullable);

// Callback to execute Rust tasks using a Swift Task
//
// Args:
//   executor: ForeignExecutor lowered into a size_t value
//   delay: Delay in MS
//   task: UniFfiRustTaskCallback to call
//   task_data: data to pass the task callback
typedef void (*UniFfiForeignExecutorCallback)(size_t, uint32_t, UniFfiRustTaskCallback _Nullable, const void * _Nullable);

typedef struct ForeignBytes
{
    int32_t len;
    const uint8_t *_Nullable data;
} ForeignBytes;

// Error definitions
typedef struct RustCallStatus {
    int8_t code;
    RustBuffer errorBuf;
} RustCallStatus;

// ⚠️ Attention: If you change this #else block (ending in `#endif // def UNIFFI_SHARED_H`) you *must* ⚠️
// ⚠️ increment the version suffix in all instances of UNIFFI_SHARED_HEADER_V4 in this file.           ⚠️
#endif // def UNIFFI_SHARED_H

// Callbacks for UniFFI Futures
typedef void (*UniFfiFutureCallbackUInt8)(const void * _Nonnull, uint8_t, RustCallStatus);
typedef void (*UniFfiFutureCallbackUnsafeMutableRawPointer)(const void * _Nonnull, void*_Nonnull, RustCallStatus);
typedef void (*UniFfiFutureCallbackUnsafeMutableRawPointer)(const void * _Nonnull, void*_Nonnull, RustCallStatus);
typedef void (*UniFfiFutureCallbackRustBuffer)(const void * _Nonnull, RustBuffer, RustCallStatus);

// Scaffolding functions
void uniffi_uniffi_wysiwyg_composer_fn_free_composermodel(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_action_states(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_backspace(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_bold(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_clear(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_code_block(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_debug_panic(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_delete(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_delete_in(void*_Nonnull ptr, uint32_t start, uint32_t end, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_enter(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_get_content_as_html(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_get_content_as_markdown(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_get_content_as_message_html(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_get_content_as_message_markdown(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_get_content_as_plain_text(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_get_current_dom_state(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_get_link_action(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_get_mentions_state(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_indent(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_inline_code(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_insert_at_room_mention(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_insert_at_room_mention_at_suggestion(void*_Nonnull ptr, RustBuffer suggestion, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_insert_mention(void*_Nonnull ptr, RustBuffer url, RustBuffer text, RustBuffer _attributes, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_insert_mention_at_suggestion(void*_Nonnull ptr, RustBuffer url, RustBuffer text, RustBuffer suggestion, RustBuffer _attributes, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_italic(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_ordered_list(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_quote(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_redo(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_remove_links(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_replace_text(void*_Nonnull ptr, RustBuffer new_text, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_replace_text_in(void*_Nonnull ptr, RustBuffer new_text, uint32_t start, uint32_t end, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_replace_text_suggestion(void*_Nonnull ptr, RustBuffer new_text, RustBuffer suggestion, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_select(void*_Nonnull ptr, uint32_t start_utf16_codeunit, uint32_t end_utf16_codeunit, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_set_content_from_html(void*_Nonnull ptr, RustBuffer html, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_set_content_from_markdown(void*_Nonnull ptr, RustBuffer markdown, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_set_link(void*_Nonnull ptr, RustBuffer url, RustBuffer attributes, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_set_link_with_text(void*_Nonnull ptr, RustBuffer url, RustBuffer text, RustBuffer attributes, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_strike_through(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_to_example_format(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_to_tree(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_underline(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_undo(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_unindent(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_method_composermodel_unordered_list(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void uniffi_uniffi_wysiwyg_composer_fn_free_composerupdate(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composerupdate_link_action(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composerupdate_menu_action(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composerupdate_menu_state(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
RustBuffer uniffi_uniffi_wysiwyg_composer_fn_method_composerupdate_text_update(void*_Nonnull ptr, RustCallStatus *_Nonnull out_status
);
void*_Nonnull uniffi_uniffi_wysiwyg_composer_fn_func_new_composer_model(RustCallStatus *_Nonnull out_status
    
);
RustBuffer ffi_wysiwyg_composer_rustbuffer_alloc(int32_t size, RustCallStatus *_Nonnull out_status
);
RustBuffer ffi_wysiwyg_composer_rustbuffer_from_bytes(ForeignBytes bytes, RustCallStatus *_Nonnull out_status
);
void ffi_wysiwyg_composer_rustbuffer_free(RustBuffer buf, RustCallStatus *_Nonnull out_status
);
RustBuffer ffi_wysiwyg_composer_rustbuffer_reserve(RustBuffer buf, int32_t additional, RustCallStatus *_Nonnull out_status
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_func_new_composer_model(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_action_states(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_backspace(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_bold(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_clear(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_code_block(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_debug_panic(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_delete(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_delete_in(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_enter(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_get_content_as_html(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_get_content_as_markdown(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_get_content_as_message_html(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_get_content_as_message_markdown(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_get_content_as_plain_text(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_get_current_dom_state(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_get_link_action(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_get_mentions_state(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_indent(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_inline_code(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_insert_at_room_mention(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_insert_at_room_mention_at_suggestion(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_insert_mention(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_insert_mention_at_suggestion(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_italic(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_ordered_list(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_quote(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_redo(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_remove_links(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_replace_text(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_replace_text_in(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_replace_text_suggestion(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_select(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_set_content_from_html(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_set_content_from_markdown(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_set_link(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_set_link_with_text(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_strike_through(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_to_example_format(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_to_tree(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_underline(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_undo(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_unindent(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composermodel_unordered_list(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composerupdate_link_action(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composerupdate_menu_action(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composerupdate_menu_state(void
    
);
uint16_t uniffi_uniffi_wysiwyg_composer_checksum_method_composerupdate_text_update(void
    
);
uint32_t ffi_wysiwyg_composer_uniffi_contract_version(void
    
);

