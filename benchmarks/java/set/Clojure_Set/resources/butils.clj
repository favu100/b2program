(ns btypes.butils
  (:require [clojure.set :as s])
  (:require [btypes.bboolean])
  (:require [btypes.bset])
  (:import (de.hhu.stups.btypes BBoolean
             BSet))
  (:gen-class :name de.hhu.stups.btypes.BUtils))


(gen-class 
     :name de.hhu.stups.btypes.BUtils
     :methods [^:static [BOOL [] de.hhu.stups.btypes.BSet]])

(def BOOL_CONST (delay (de.hhu.stups.btypes.BSet. #{(de.hhu.stups.btypes.BBoolean. true) (de.hhu.stups.btypes.BBoolean. false)})))


(defn BOOL []
  @BOOL_CONST)
  

