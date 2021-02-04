#ifndef __CE_DESC_UNIFIED_H__
#define __CE_DESC_UNIFIED_H__

struct CE_src_desc {
    CE_addr_t src_ptr;
#if _BYTE_ORDER == _BIG_ENDIAN
    u_int32_t  meta_data:12,
               target_int_disable:1,
               host_int_disable:1,
               byte_swap:1,
               gather:1,
               nbytes:16;
#else

    u_int32_t nbytes:16,
              gather:1,
              byte_swap:1,
              host_int_disable:1,
              target_int_disable:1,
              meta_data:12;
#endif
};

struct dest_desc_info {
#if _BYTE_ORDER == _BIG_ENDIAN
    u_int32_t  meta_data:12,
               target_int_disable:1,
               host_int_disable:1,
               byte_swap:1,
               gather:1,
               nbytes:16;
#else
    u_int32_t nbytes:16,
              gather:1,
              byte_swap:1,
              host_int_disable:1,
              target_int_disable:1,
              meta_data:12;
#endif
};

struct CE_dest_desc {
    CE_addr_t dest_ptr;
    struct dest_desc_info info;
};

#endif //__CE_DESC_UNIFIED_H__
