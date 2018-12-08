/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "PathFrameModule"
 * 	found in "./PathFrameModule.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_PathPrediction_H_
#define	_PathPrediction_H_


#include <asn_application.h>

/* Including external dependencies */
#include "RadiusOfCurvature.h"
#include "Confidence.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PathPrediction */
typedef struct PathPrediction {
	RadiusOfCurvature_t	 radiusOfCurve;
	Confidence_t	 confidence;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PathPrediction_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PathPrediction;

#ifdef __cplusplus
}
#endif

#endif	/* _PathPrediction_H_ */
#include <asn_internal.h>