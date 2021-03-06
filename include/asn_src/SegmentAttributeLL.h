/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "DataElementsModule"
 * 	found in "./DataElementsModule.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_SegmentAttributeLL_H_
#define	_SegmentAttributeLL_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum SegmentAttributeLL {
	SegmentAttributeLL_reserved	= 0,
	SegmentAttributeLL_doNotBlock	= 1,
	SegmentAttributeLL_whiteLine	= 2,
	SegmentAttributeLL_mergingLaneLeft	= 3,
	SegmentAttributeLL_mergingLaneRight	= 4,
	SegmentAttributeLL_curbOnLeft	= 5,
	SegmentAttributeLL_curbOnRight	= 6,
	SegmentAttributeLL_loadingzoneOnLeft	= 7,
	SegmentAttributeLL_loadingzoneOnRight	= 8,
	SegmentAttributeLL_turnOutPointOnLeft	= 9,
	SegmentAttributeLL_adjacentParkingOnLeft	= 10,
	SegmentAttributeLL_sharedBikeLane	= 11,
	SegmentAttributeLL_bikeBoxInFront	= 12,
	SegmentAttributeLL_transitStopOnLeft	= 13,
	SegmentAttributeLL_transitStopOnRight	= 14,
	SegmentAttributeLL_transitStopInLane	= 15,
	SegmentAttributeLL_sharedWithTrackedVehicle	= 16,
	SegmentAttributeLL_safeIsland	= 17,
	SegmentAttributeLL_lowCurbsPresent	= 18,
	SegmentAttributeLL_rumbleStripPresent	= 19,
	SegmentAttributeLL_audibleSignalingPresent	= 20,
	SegmentAttributeLL_adaptiveTimingPresent	= 21,
	SegmentAttributeLL_rfSignalRequestPresent	= 22,
	SegmentAttributeLL_partialCurbIntrusion	= 23,
	SegmentAttributeLL_taperToLeft	= 24,
	SegmentAttributeLL_taperToCenterLine	= 25,
	SegmentAttributeLL_parallelParking	= 26,
	SegmentAttributeLL_headInParking	= 27,
	SegmentAttributeLL_freeParking	= 28,
	SegmentAttributeLL_timeRestrictionsOnParking	= 29,
	SegmentAttributeLL_costToPark	= 30,
	SegmentAttributeLL_midBlockCurbPresent	= 31,
	SegmentAttributeLL_unEvenPavementPresent	= 32
	/*
	 * Enumeration is extensible
	 */
} e_SegmentAttributeLL;

/* SegmentAttributeLL */
typedef long	 SegmentAttributeLL_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SegmentAttributeLL;
asn_struct_free_f SegmentAttributeLL_free;
asn_struct_print_f SegmentAttributeLL_print;
asn_constr_check_f SegmentAttributeLL_constraint;
ber_type_decoder_f SegmentAttributeLL_decode_ber;
der_type_encoder_f SegmentAttributeLL_encode_der;
xer_type_decoder_f SegmentAttributeLL_decode_xer;
xer_type_encoder_f SegmentAttributeLL_encode_xer;
oer_type_decoder_f SegmentAttributeLL_decode_oer;
oer_type_encoder_f SegmentAttributeLL_encode_oer;
per_type_decoder_f SegmentAttributeLL_decode_uper;
per_type_encoder_f SegmentAttributeLL_encode_uper;

#ifdef __cplusplus
}
#endif

#endif	/* _SegmentAttributeLL_H_ */
#include <asn_internal.h>
