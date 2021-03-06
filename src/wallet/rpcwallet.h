// Copyright (c) 2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_WALLET_RPCWALLET_H
#define BITCOIN_WALLET_RPCWALLET_H

class CCoinControl;
class CRPCTable;
class CWalletTx;
class JSONRPCRequest;

void RegisterWalletRPCCommands(CRPCTable &t);

/**
 * Figures out what wallet, if any, to use for a JSONRPCRequest.
 *
 * @param[in] request JSONRPCRequest that wishes to access a wallet
 * @return NULL if no wallet should be used, or a pointer to the CWallet
 */
CWallet *GetWalletForJSONRPCRequest(const JSONRPCRequest&);

std::string HelpRequiringPassphrase(CWallet *);
void EnsureWalletIsUnlocked(CWallet *);
bool EnsureWalletIsAvailable(CWallet *, bool avoidException);
void SendMoneyToScript(CWallet* pwallet, const CScript& scriptPubKey,
                       const CTxIn* withInput, CAmount nValue,
                       bool fSubtractFeeFromAmount, CWalletTx& wtxNew,
                       CCoinControl* coin_control = nullptr);

#endif //BITCOIN_WALLET_RPCWALLET_H
