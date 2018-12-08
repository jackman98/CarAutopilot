/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DataElementsModule"
 * 	found in "./DataElementsModule.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_DataParameters_H_
#define	_DataParameters_H_


#include <asn_application.h>

/* Including external dependencies */
#include <IA5String.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* DataParameters */
typedef struct DataParameters {
	IA5String_t	 processMethod;
	IA5String_t	 processAgency;
	IA5String_t	 lastCheckedDate;
	IA5String_t	 geoidUsed;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DataParameters_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DataParameters;
extern asn_SEQUENCE_specifics_t asn_SPC_DataParameters_specs_1;
extern asn_TYPE_member_t asn_MBR_DataParameters_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _DataParameters_H_ */
#include <asn_internal.h>
