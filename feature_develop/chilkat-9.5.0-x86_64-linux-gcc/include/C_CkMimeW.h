// This is a generated source file for Chilkat version 9.5.0.69
#ifndef _C_CkMimeWH
#define _C_CkMimeWH
#include "chilkatDefs.h"

#include "Chilkat_C.h"


CK_VISIBLE_PUBLIC HCkMimeW CkMimeW_Create(void);
CK_VISIBLE_PUBLIC void CkMimeW_Dispose(HCkMimeW handle);
CK_VISIBLE_PUBLIC void CkMimeW_getBoundary(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putBoundary(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_boundary(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getCharset(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putCharset(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_charset(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getContentType(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putContentType(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_contentType(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getCurrentDateTime(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_currentDateTime(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getDebugLogFilePath(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putDebugLogFilePath(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_debugLogFilePath(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getDisposition(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putDisposition(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_disposition(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getEncoding(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putEncoding(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_encoding(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getFilename(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putFilename(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_filename(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getLastErrorHtml(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_lastErrorHtml(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getLastErrorText(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_lastErrorText(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getLastErrorXml(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_lastErrorXml(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_getLastMethodSuccess(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void  CkMimeW_putLastMethodSuccess(HCkMimeW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC void CkMimeW_getMicalg(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putMicalg(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_micalg(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getName(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putName(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_name(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC int CkMimeW_getNumEncryptCerts(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC int CkMimeW_getNumHeaderFields(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC int CkMimeW_getNumParts(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC int CkMimeW_getNumSignerCerts(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getOaepHash(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putOaepHash(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_oaepHash(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_getOaepPadding(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void  CkMimeW_putOaepPadding(HCkMimeW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC void CkMimeW_getPkcs7CryptAlg(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putPkcs7CryptAlg(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_pkcs7CryptAlg(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC int CkMimeW_getPkcs7KeyLength(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void  CkMimeW_putPkcs7KeyLength(HCkMimeW cHandle, int newVal);
CK_VISIBLE_PUBLIC void CkMimeW_getProtocol(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putProtocol(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_protocol(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getSigningAlg(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putSigningAlg(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_signingAlg(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_getSigningHashAlg(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC void  CkMimeW_putSigningHashAlg(HCkMimeW cHandle, const wchar_t *newVal);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_signingHashAlg(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_getUnwrapExtras(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void  CkMimeW_putUnwrapExtras(HCkMimeW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC BOOL CkMimeW_getUseMmDescription(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void  CkMimeW_putUseMmDescription(HCkMimeW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC BOOL CkMimeW_getUseXPkcs7(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void  CkMimeW_putUseXPkcs7(HCkMimeW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC BOOL CkMimeW_getVerboseLogging(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void  CkMimeW_putVerboseLogging(HCkMimeW cHandle, BOOL newVal);
CK_VISIBLE_PUBLIC void CkMimeW_getVersion(HCkMimeW cHandle, HCkString retval);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_version(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_AddContentLength(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AddDecryptCert(HCkMimeW cHandle, HCkCertW cert);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AddDetachedSignature(HCkMimeW cHandle, HCkCertW cert);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AddDetachedSignature2(HCkMimeW cHandle, HCkCertW cert, BOOL transferHeaderFields);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AddDetachedSignaturePk(HCkMimeW cHandle, HCkCertW cert, HCkPrivateKeyW privateKey);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AddDetachedSignaturePk2(HCkMimeW cHandle, HCkCertW cert, HCkPrivateKeyW privateKey, BOOL transferHeaderFields);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AddEncryptCert(HCkMimeW cHandle, HCkCertW cert);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AddHeaderField(HCkMimeW cHandle, const wchar_t *name, const wchar_t *value);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AddPfxSourceData(HCkMimeW cHandle, HCkByteData pfxFileData, const wchar_t *pfxPassword);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AddPfxSourceFile(HCkMimeW cHandle, const wchar_t *pfxFilePath, const wchar_t *password);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AppendPart(HCkMimeW cHandle, HCkMimeW mime);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AppendPartFromFile(HCkMimeW cHandle, const wchar_t *filename);
CK_VISIBLE_PUBLIC BOOL CkMimeW_AsnBodyToXml(HCkMimeW cHandle, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_asnBodyToXml(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_ClearEncryptCerts(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_ContainsEncryptedParts(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_ContainsSignedParts(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_Convert8Bit(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_ConvertToMultipartAlt(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_ConvertToMultipartMixed(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_ConvertToSigned(HCkMimeW cHandle, HCkCertW cert);
CK_VISIBLE_PUBLIC BOOL CkMimeW_ConvertToSignedPk(HCkMimeW cHandle, HCkCertW cert, HCkPrivateKeyW privateKey);
CK_VISIBLE_PUBLIC BOOL CkMimeW_Decrypt(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_Decrypt2(HCkMimeW cHandle, HCkCertW cert, HCkPrivateKeyW privateKey);
CK_VISIBLE_PUBLIC BOOL CkMimeW_DecryptUsingCert(HCkMimeW cHandle, HCkCertW cert);
CK_VISIBLE_PUBLIC BOOL CkMimeW_DecryptUsingPfxData(HCkMimeW cHandle, HCkByteData pfxData, const wchar_t *password);
CK_VISIBLE_PUBLIC BOOL CkMimeW_DecryptUsingPfxFile(HCkMimeW cHandle, const wchar_t *pfxFilePath, const wchar_t *pfxPassword);
CK_VISIBLE_PUBLIC BOOL CkMimeW_Encrypt(HCkMimeW cHandle, HCkCertW cert);
CK_VISIBLE_PUBLIC BOOL CkMimeW_EncryptN(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC HCkStringArrayW CkMimeW_ExtractPartsToFiles(HCkMimeW cHandle, const wchar_t *dirPath);
CK_VISIBLE_PUBLIC HCkCertW CkMimeW_FindIssuer(HCkMimeW cHandle, HCkCertW cert);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetBodyBd(HCkMimeW cHandle, HCkBinDataW binDat);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetBodyBinary(HCkMimeW cHandle, HCkByteData outData);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetBodyDecoded(HCkMimeW cHandle, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getBodyDecoded(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetBodyEncoded(HCkMimeW cHandle, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getBodyEncoded(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC HCkCertW CkMimeW_GetEncryptCert(HCkMimeW cHandle, int index);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetEntireBody(HCkMimeW cHandle, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getEntireBody(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetEntireHead(HCkMimeW cHandle, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getEntireHead(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetHeaderField(HCkMimeW cHandle, const wchar_t *fieldName, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getHeaderField(HCkMimeW cHandle, const wchar_t *fieldName);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetHeaderFieldAttribute(HCkMimeW cHandle, const wchar_t *name, const wchar_t *attrName, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getHeaderFieldAttribute(HCkMimeW cHandle, const wchar_t *name, const wchar_t *attrName);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetHeaderFieldName(HCkMimeW cHandle, int index, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getHeaderFieldName(HCkMimeW cHandle, int index);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetHeaderFieldValue(HCkMimeW cHandle, int index, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getHeaderFieldValue(HCkMimeW cHandle, int index);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetMime(HCkMimeW cHandle, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getMime(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetMimeBd(HCkMimeW cHandle, HCkBinDataW bindat);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetMimeBytes(HCkMimeW cHandle, HCkByteData outBytes);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetMimeSb(HCkMimeW cHandle, HCkStringBuilderW sb);
CK_VISIBLE_PUBLIC HCkMimeW CkMimeW_GetPart(HCkMimeW cHandle, int index);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetSignatureSigningTime(HCkMimeW cHandle, int index, SYSTEMTIME *outSysTime);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetSignatureSigningTimeStr(HCkMimeW cHandle, int index, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getSignatureSigningTimeStr(HCkMimeW cHandle, int index);
CK_VISIBLE_PUBLIC HCkCertW CkMimeW_GetSignerCert(HCkMimeW cHandle, int index);
CK_VISIBLE_PUBLIC HCkCertChainW CkMimeW_GetSignerCertChain(HCkMimeW cHandle, int index);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetStructure(HCkMimeW cHandle, const wchar_t *fmt, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getStructure(HCkMimeW cHandle, const wchar_t *fmt);
CK_VISIBLE_PUBLIC BOOL CkMimeW_GetXml(HCkMimeW cHandle, HCkString outStr);
CK_VISIBLE_PUBLIC const wchar_t *CkMimeW_getXml(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_HasSignatureSigningTime(HCkMimeW cHandle, int index);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsApplicationData(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsAttachment(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsAudio(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsEncrypted(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsHtml(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsImage(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsMultipart(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsMultipartAlternative(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsMultipartMixed(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsMultipartRelated(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsPlainText(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsSigned(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsText(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsUnlocked(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsVideo(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_IsXml(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC HCkJsonObjectW CkMimeW_LastJsonData(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_LoadMime(HCkMimeW cHandle, const wchar_t *mimeMsg);
CK_VISIBLE_PUBLIC BOOL CkMimeW_LoadMimeBd(HCkMimeW cHandle, HCkBinDataW bindat);
CK_VISIBLE_PUBLIC BOOL CkMimeW_LoadMimeBytes(HCkMimeW cHandle, HCkByteData binData);
CK_VISIBLE_PUBLIC BOOL CkMimeW_LoadMimeFile(HCkMimeW cHandle, const wchar_t *fileName);
CK_VISIBLE_PUBLIC BOOL CkMimeW_LoadMimeSb(HCkMimeW cHandle, HCkStringBuilderW sb);
CK_VISIBLE_PUBLIC BOOL CkMimeW_LoadXml(HCkMimeW cHandle, const wchar_t *xml);
CK_VISIBLE_PUBLIC BOOL CkMimeW_LoadXmlFile(HCkMimeW cHandle, const wchar_t *fileName);
CK_VISIBLE_PUBLIC BOOL CkMimeW_NewMessageRfc822(HCkMimeW cHandle, HCkMimeW mimeObject);
CK_VISIBLE_PUBLIC BOOL CkMimeW_NewMultipartAlternative(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_NewMultipartMixed(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC BOOL CkMimeW_NewMultipartRelated(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_RemoveHeaderField(HCkMimeW cHandle, const wchar_t *fieldName, BOOL bAllOccurrences);
CK_VISIBLE_PUBLIC BOOL CkMimeW_RemovePart(HCkMimeW cHandle, int index);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SaveBody(HCkMimeW cHandle, const wchar_t *filename);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SaveLastError(HCkMimeW cHandle, const wchar_t *path);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SaveMime(HCkMimeW cHandle, const wchar_t *filename);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SaveXml(HCkMimeW cHandle, const wchar_t *filename);
CK_VISIBLE_PUBLIC void CkMimeW_SetBody(HCkMimeW cHandle, const wchar_t *str);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SetBodyFromBinary(HCkMimeW cHandle, HCkByteData binData);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SetBodyFromEncoded(HCkMimeW cHandle, const wchar_t *encoding, const wchar_t *str);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SetBodyFromFile(HCkMimeW cHandle, const wchar_t *fileName);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SetBodyFromHtml(HCkMimeW cHandle, const wchar_t *str);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SetBodyFromPlainText(HCkMimeW cHandle, const wchar_t *str);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SetBodyFromXml(HCkMimeW cHandle, const wchar_t *str);
#if defined(CK_CSP_INCLUDED)
CK_VISIBLE_PUBLIC BOOL CkMimeW_SetCSP(HCkMimeW cHandle, HCkCspW csp);
#endif
CK_VISIBLE_PUBLIC BOOL CkMimeW_SetHeaderField(HCkMimeW cHandle, const wchar_t *name, const wchar_t *value);
CK_VISIBLE_PUBLIC BOOL CkMimeW_SetVerifyCert(HCkMimeW cHandle, HCkCertW cert);
CK_VISIBLE_PUBLIC BOOL CkMimeW_UnlockComponent(HCkMimeW cHandle, const wchar_t *unlockCode);
CK_VISIBLE_PUBLIC BOOL CkMimeW_UnwrapSecurity(HCkMimeW cHandle);
CK_VISIBLE_PUBLIC void CkMimeW_UrlEncodeBody(HCkMimeW cHandle, const wchar_t *charset);
CK_VISIBLE_PUBLIC BOOL CkMimeW_UseCertVault(HCkMimeW cHandle, HCkXmlCertVaultW vault);
CK_VISIBLE_PUBLIC BOOL CkMimeW_Verify(HCkMimeW cHandle);
#endif
