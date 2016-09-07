#ifndef __SIGNATURE_H__
#define __SIGNATURE_H__

#include <string>
#include <memory>
#include <tuple>

#include "../domain/entity.hpp"

namespace signature{

  //=== Deprecated use for debug. ===
  bool verify(std::string signature,std::string message, std::string publicKeyName);
  std::string sign(std::string message,std::string privateKeyName,std::string publicKeyName);
  bool generateKeyPairAndSave(std::string filenamePrefix,std::string keyPath);
  //===

  template<typename T>
  bool verify(std::string signature,std::string message,T dummy){
    //ToDo throw illegal type exception
  }
  template<typename T>
  std::string sign(std::string message,T dummy){
    //ToDo throw illegal type exception
  }
  template<typename T>
  std::string generateKeyPair(T dummy){
    //ToDo throw illegal type exception
  }

  template<>
  bool verify<std::shared_ptr<Entity>>(
    const std::string signature,
    const std::string message,
    const std::shared_ptr<Entity> entity){
    //ToDo
  }
  template<>
  std::string sign<std::shared_ptr<Entity>>(
    const std::string message,
    const std::shared_ptr<Entity> entity){
    //ToDo
  }

  std::tuple<
    unsigned char*,
    unsigned char*
  > generateKeyPair(){

    unsigned char publicKey[32], privateKey[64], seed[32];
    ed25519_create_seed(seed);
    ed25519_create_keypair(publicKey, privateKey, seed);

    return std::make_tuple( publicKey, privateKey);
  }
};

#endif
