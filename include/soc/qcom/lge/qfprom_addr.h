#ifndef __MACH_QFPROM_ADDR_8996_H__
#define __MACH_QFPROM_ADDR_8996_H__

#define SEC_PATH "/dev/block/bootdevice/by-name/sec"
/* QFPROM address to blow */
#define QFPROM_CTRL_BASE        (0x00070000)

#define QFPROM_RD_PERM			(QFPROM_CTRL_BASE + 0x0150) /* 0x00070150 */
#define QFPROM_WR_PERM			(QFPROM_CTRL_BASE + 0x0158) /* 0x00070150 */
#define QFPROM_ANTIROLLBACK1	(QFPROM_CTRL_BASE + 0x0168) /* 0x00070168 */	//xbl, 
#define QFPROM_ANTIROLLBACK2	(QFPROM_CTRL_BASE + 0x0170) /* 0x00070170 */	//pil, tz, rpm
#define QFPROM_ANTIROLLBACK3	(QFPROM_CTRL_BASE + 0x0178) /* 0x00070178 */	//pil, tqs, debugpolicy, device cfg
#define QFPROM_ANTIROLLBACK4	(QFPROM_CTRL_BASE + 0x0180) /* 0x00070180 */	//mba, mss
#define QFPROM_OEM_CONFIG1		(QFPROM_CTRL_BASE + 0x0188) /* 0x00070188 */
#define QFPROM_OEM_CONFIG2		(QFPROM_CTRL_BASE + 0x0190) /* 0x00070190 */
#define QFPROM_OEM_CONFIG3		(QFPROM_CTRL_BASE + 0x0198) /* 0x00070198 */
#define QFPROM_FEC_EN			(QFPROM_CTRL_BASE + 0x0160) /* 0x00070160 */
#define QFPROM_SEC_HW_KEY		(QFPROM_CTRL_BASE + 0x03B0) /* 0x000703B0 */
#define QFPROM_SEC_HW_KEY1		(QFPROM_CTRL_BASE + 0x03B8) /* 0x000703B0 */
#define QFPROM_SEC_HW_KEY2		(QFPROM_CTRL_BASE + 0x03C0) /* 0x000703B0 */
#define QFPROM_SEC_HW_KEY3		(QFPROM_CTRL_BASE + 0x03C8) /* 0x000703B0 */
#define QFPROM_SEC_HW_KEY4		(QFPROM_CTRL_BASE + 0x03D0) /* 0x000703B0 */

#define QFPROM_OEM_PK_HASH		(QFPROM_CTRL_BASE + 0x01C8) /* 0x000701C8 */
#define QFPROM_SEC_ENABLE		(QFPROM_CTRL_BASE + 0x0378) /* 0x00070378 */
#define QFPROM_HW_KEY_STATUS	(QFPROM_CTRL_BASE + 0x208C) /* 0x0007208C */
#define QFPROM_CORR_SERIAL_NUM  (QFPROM_CTRL_BASE + 0x4138) /* 0x00074138 */

typedef enum {
  QFPROM_RESULT_OEM_CONFIG		= 0,
  QFPROM_RESULT_SEC_ENABLE		= 1,
  QFPROM_RESULT_DBG_DISABLE		= 2,
  QFPROM_RESULT_DBG_DISABLE2	= 2,
  QFPROM_RESULT_SEC_HW_KEY		= 3,
  QFPROM_RESULT_RD_PERM			= 4,
  QFPROM_RESULT_WR_PERM			= 4,
  QFPROM_RESULT_PRODUCT_ID		= 5,
  QFPROM_RESULT_FEC_EN			= 6,
  QFPROM_RESULT_OEM_PK_HASH		= 7,
  QFPROM_RESULT_MAX
} qfprom_result_etype;

typedef struct {
  u32 type;
  u32 addr;
  u32 lsb;
  u32 msb;
} qfprom_result_bits;

qfprom_result_bits result_bits[] = {
  {QFPROM_RESULT_OEM_CONFIG,	QFPROM_OEM_CONFIG2,	0x00000000, 0x0000FFFF},	//oem hw id
  {QFPROM_RESULT_SEC_ENABLE,	QFPROM_SEC_ENABLE,	0x00FFFFFF, 0xFF000000},	//secure boot enable check
  {QFPROM_RESULT_DBG_DISABLE,	QFPROM_OEM_CONFIG1,	0xFFFFFFFF, 0xFFFFFFFF},	//debug disable check
  {QFPROM_RESULT_DBG_DISABLE2,	QFPROM_OEM_CONFIG2,	0x00000FFF, 0x00000000},	//debug disable check
  {QFPROM_RESULT_SEC_HW_KEY,	QFPROM_SEC_HW_KEY,	0xFFFFFFFF, 0xFFFFFFFF},	//shk check. don't this addr and value.
  {QFPROM_RESULT_PRODUCT_ID,	QFPROM_OEM_CONFIG2, 0x00000000, 0xFFFF0000},	//oem product id
  {QFPROM_RESULT_RD_PERM,		QFPROM_RD_PERM,		0xFFFFFFFF, 0x00000000},
  {QFPROM_RESULT_WR_PERM,		QFPROM_WR_PERM,		0xFFFFFFFF, 0x00000000},
  {QFPROM_RESULT_FEC_EN,		QFPROM_FEC_EN,		0xFFFFFFFF, 0x00000000},
  {QFPROM_RESULT_OEM_PK_HASH,	QFPROM_OEM_PK_HASH,	0xFFFFFFFF, 0xFFFFFFFF},
};

/* secondary hw key status flag */
#define SEC_KEY_DERIVATION_BLOWN    (0x00000002)

/* ANTI_ROLLBACK Version check */
typedef enum {
  QFPROM_VERSION_SBL1   = 0,
  QFPROM_VERSION_TZ     = 1,
  QFPROM_VERSION_PIL    = 2,
  QFPROM_VERSION_APPSBL = 3,
  QFPROM_VERSION_RPM    = 4,
  QFPROM_VERSION_HYP    = 5,
  QFPROM_VERSION_MBA    = 6,
  QFPROM_VERSION_MODEM  = 7,
  QFPROM_VERSION_MAX
} qfprom_version_etype;

#define RV_IMAGE_NAME_SIZE 10
#define RV_ERR_DISABLED -1
#define RV_ERR_NOT_SUPPORTED -2
#define RV_ERR_EXCEED_NAME_SIZE -3

typedef struct {
  u32 type;
  char name[RV_IMAGE_NAME_SIZE];
} qfprom_version_typename;

qfprom_result_bits anti_rollback_enable = {QFPROM_RESULT_OEM_CONFIG, QFPROM_OEM_CONFIG3, 0x00000000, 0x0000000F};

#define DEVICE_ID_INPUT_SIZE 16
#define SHA256_SIZE 32
#define SHA256_SIZE_CHAR 64
qfprom_result_bits qfprom_device_id = {QFPROM_VERSION_MAX, QFPROM_CORR_SERIAL_NUM, 0xFFFFFFFF, 0xFFFFFFFF};

qfprom_version_typename version_type[QFPROM_VERSION_MAX] = {
  {QFPROM_VERSION_SBL1,   "sbl1"  },
  {QFPROM_VERSION_TZ,     "tz"    },
  {QFPROM_VERSION_PIL,    "pil"   },
  {QFPROM_VERSION_APPSBL, "appsbl"},
  {QFPROM_VERSION_RPM,    "rpm"   },
  {QFPROM_VERSION_HYP,    "hyp"   },
  {QFPROM_VERSION_MBA,    "mba"   },
  {QFPROM_VERSION_MODEM,  "modem" },
};

qfprom_result_bits version_bits[4] = {
  {QFPROM_VERSION_SBL1,    QFPROM_ANTIROLLBACK1,  0xFFFFFFFF,  0xFFFFFFFF},
  {QFPROM_VERSION_TZ,      QFPROM_ANTIROLLBACK2,  0x00000000,  0x0001FFFF},
  {QFPROM_VERSION_APPSBL,  QFPROM_ANTIROLLBACK1,  0xFFFFFFFF,  0xFFFFFFFF},
  {QFPROM_VERSION_RPM,     QFPROM_ANTIROLLBACK2,  0x00000000,  0x01FE0000},
};

#endif // __MACH_QFPROM_ADDR_8996_H__
