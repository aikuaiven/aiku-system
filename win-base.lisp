					; -*- mode: lisp; -*-
(or (find-package :aiku) (load "~/project/aiku-system/aiku-win-64-w-package.lisp"))
(cffi:load-foreign-library "kernel32.dll")

(in-package :aiku)

;kernel32.dll structures and constants

;maximum path length in characters
(defconstant +max-path+ 260)

;access rights
(defconstant +delete-right+ #x00010000)
(defconstant +read-control+ #x00020000)
(defconstant +write-dac+ #x00040000)
(defconstant +write-owner+ #x00080000)
(defconstant +synchronize+ #x00100000)
(defconstant +standard-rights-read+ +read-control+)
(defconstant +standard-rights-write+ +read-control+)
(defconstant +standard-rights-execute+ +read-control+)
(defconstant +standard-rights-required+ #x000f0000)
(defconstant +standard-rights-all+ #x001f0000)
(defconstant +specific-rights-all+ #x0000ffff)
(defconstant +access-system-security+ #x01000000)
(defconstant +maximum-allowed+ #x02000000)
(defconstant +generic-read+ #x80000000)
(defconstant +generic-write+ #x40000000)
(defconstant +generic-execute+ #x20000000)
(defconstant +generic-all+ #x10000000)
(defconstant +process-terminate+ #x00000001)
(defconstant +process-create-thread+ #x00000002)
(defconstant +process-vm-operation+ #x00000008)
(defconstant +process-vm-read+ #x00000010)
(defconstant +process-vm-write+ #x00000020)
(defconstant +process-dup-handle+ #x00000040)
(defconstant +process-create-process+ #x00000080)
(defconstant +process-set-quota+ #x00000100)
(defconstant +process-set-information+ #x00000200)
(defconstant +process-query-information+ #x00000400)
(defconstant +process-all-access+ (+ +standard-rights-required+ +synchronize+ #x0fff))
(defconstant +file-share-read+ #x00000001)
(defconstant +file-share-write+ #x00000002)
(defconstant +file-share-delete+ #x00000004)

;createfile actions
(defconstant +create-new+ 1)
(defconstant +create-always+ 2)
(defconstant +open-existing+ 3)
(defconstant +open-always+ 4)
(defconstant +truncate-existing+ 5)

;openfile modes
(defconstant +of-read+ #x0000)
(defconstant +of-write+ #x0001)
(defconstant +of-readwrite+ #x0002)
(defconstant +of-share-compat+ #x0000)
(defconstant +of-share-exclusive+ #x0010)
(defconstant +of-share-deny-write+ #x0020)
(defconstant +of-share-deny-read+ #x0030)
(defconstant +of-share-deny-none+ #x0040)
(defconstant +of-parse+ #x0100)
(defconstant +of-delete+ #x0200)
(defconstant +of-verify+ #x0400)
(defconstant +of-cancel+ #x0800)
(defconstant +of-create+ #x1000)
(defconstant +of-prompt+ #x2000)
(defconstant +of-exist+ #x4000)
(defconstant +of-reopen+ #x8000)

;setfilepointer methods
(defconstant +file-begin+ 0)
(defconstant +file-current+ 1)
(defconstant +file-end+ 2)

;file attributes
(defconstant +file-attribute-readonly+ #x001)
(defconstant +file-attribute-hidden+ #x002)
(defconstant +file-attribute-system+ #x004)
(defconstant +file-attribute-directory+ #x010)
(defconstant +file-attribute-archive+ #x020)
(defconstant +file-attribute-normal+ #x080)
(defconstant +file-attribute-temporary+ #x100)
(defconstant +file-attribute-compressed+ #x800)

;file flags
(defconstant +file-flag-write-through+ #x80000000)
(defconstant +file-flag-overlapped+ #x40000000)
(defconstant +file-flag-no-buffering+ #x20000000)
(defconstant +file-flag-random-access+ #x10000000)
(defconstant +file-flag-sequential-scan+ #x08000000)
(defconstant +file-flag-delete-on-close+ #x04000000)
(defconstant +file-flag-backup-semantics+ #x02000000)
(defconstant +file-flag-posix-semantics+ #x01000000)

;notify filters
(defconstant +file-notify-change-file-name+ #x001)
(defconstant +file-notify-change-dir-name+ #x002)
(defconstant +file-notify-change-attributes+ #x004)
(defconstant +file-notify-change-size+ #x008)
(defconstant +file-notify-change-last-write+ #x010)
(defconstant +file-notify-change-security+ #x100)

;file types
(defconstant +file-type-unknown+ 0)
(defconstant +file-type-disk+ 1)
(defconstant +file-type-char+ 2)
(defconstant +file-type-pipe+ 3)
(defconstant +file-type-remote+ #x8000)

;lockfileex flags
(defconstant +lockfile-fail-immediately+ 1)
(defconstant +lockfile-exclusive-lock+ 2)

;movefileex flags
(defconstant +movefile-replace-existing+ 1)
(defconstant +movefile-copy-allowed+ 2)
(defconstant +movefile-delay-until-reboot+ 4)
(defconstant +movefile-write-through+ 8)

;findfirstfileex flags
(defconstant +find-first-ex-case-sensitive+ 1)

;device handles
(defconstant +invalid-handle-value+ -1)
(defconstant +std-input-handle+ -10)
(defconstant +std-output-handle+ -11)
(defconstant +std-error-handle+ -12)

;duplicatehandle options
(defconstant +duplicate-close-source+ 1)
(defconstant +duplicate-same-access+ 2)

;file mapping acccess rights
(defconstant +section-query+ #x01)
(defconstant +section-map-write+ #x02)
(defconstant +section-map-read+ #x04)
(defconstant +section-map-execute+ #x08)
(defconstant +section-extend-size+ #x10)
(defconstant +section-all-access+ (+ +standard-rights-required+ +section-query+ +section-map-write+ +section-map-read+ +section-map-execute+ +section-extend-size+))
(defconstant +file-map-copy+ +section-query+)
(defconstant +file-map-write+ +section-map-write+)
(defconstant +file-map-read+ +section-map-read+)
(defconstant +file-map-all-access+ +section-all-access+)

;file system flags
(defconstant +file-case-sensitive-search+ #x0001)
(defconstant +file-case-preserved-names+ #x0002)
(defconstant +file-unicode-on-disk+ #x0004)
(defconstant +file-persistent-acls+ #x0008)
(defconstant +file-file-compression+ #x0010)
(defconstant +file-volume-is-compressed+ #x8000)
(defconstant +fs-case-is-preserved+ +file-case-preserved-names+)
(defconstant +fs-case-sensitive+ +file-case-sensitive-search+)
(defconstant +fs-unicode-stored-on-disk+ +file-unicode-on-disk+)
(defconstant +fs-persistent-acls+ +file-persistent-acls+)

;drive types
(defconstant +drive-unknown+ 0)
(defconstant +drive-no-root-dir+ 1)
(defconstant +drive-removable+ 2)
(defconstant +drive-fixed+ 3)
(defconstant +drive-remote+ 4)
(defconstant +drive-cdrom+ 5)
(defconstant +drive-ramdisk+ 6)

;pipe modes
(defconstant +pipe-access-inbound+ 1)
(defconstant +pipe-access-outbound+ 2)
(defconstant +pipe-access-duplex+ 3)
(defconstant +pipe-client-end+ 0)
(defconstant +pipe-server-end+ 1)
(defconstant +pipe-wait+ 0)
(defconstant +pipe-nowait+ 1)
(defconstant +pipe-readmode-byte+ 0)
(defconstant +pipe-readmode-message+ 2)
(defconstant +pipe-type-byte+ 0)
(defconstant +pipe-type-message+ 4)
(defconstant +pipe-unlimited-instances+ 255)

;global memory flags
(defconstant +gmem-fixed+ #x0000)
(defconstant +gmem-moveable+ #x0002)
(defconstant +gmem-nocompact+ #x0010)
(defconstant +gmem-nodiscard+ #x0020)
(defconstant +gmem-zeroinit+ #x0040)
(defconstant +gmem-modify+ #x0080)
(defconstant +gmem-discardable+ #x0100)
(defconstant +gmem-not-banked+ #x1000)
(defconstant +gmem-share+ #x2000)
(defconstant +gmem-ddeshare+ #x2000)
(defconstant +gmem-notify+ #x4000)
(defconstant +gmem-lower+ +gmem-not-banked+)
(defconstant +gmem-valid-flags+ #x7f72)
(defconstant +gmem-invalid-handle+ #x8000)
(defconstant +gmem-discarded+ #x4000)
(defconstant +gmem-lockcount+ #x0ff)
(defconstant +ghnd+ (+ +gmem-moveable+ +gmem-zeroinit+))
(defconstant +gptr+ (+ +gmem-fixed+ +gmem-zeroinit+))

;local memory flags
(defconstant +lmem-fixed+ #x0000)
(defconstant +lmem-moveable+ #x0002)
(defconstant +lmem-nocompact+ #x0010)
(defconstant +lmem-nodiscard+ #x0020)
(defconstant +lmem-zeroinit+ #x0040)
(defconstant +lmem-modify+ #x0080)
(defconstant +lmem-discardable+ #x0f00)
(defconstant +lmem-valid-flags+ #x0f72)
(defconstant +lmem-invalid-handle+ #x8000)
(defconstant +lhnd+ (+ +lmem-moveable+ +lmem-zeroinit+))
(defconstant +lptr+ (+ +lmem-fixed+ +lmem-zeroinit+))
(defconstant +lmem-discarded+ #x4000)
(defconstant +lmem-lockcount+ #x00ff)

;page access flags
(defconstant +page-noaccess+ #x001)
(defconstant +page-readonly+ #x002)
(defconstant +page-readwrite+ #x004)
(defconstant +page-writecopy+ #x008)
(defconstant +page-execute+ #x010)
(defconstant +page-execute-read+ #x020)
(defconstant +page-execute-readwrite+ #x040)
(defconstant +page-execute-writecopy+ #x080)
(defconstant +page-guard+ #x100)
(defconstant +page-nocache+ #x200)

;memory allocation flags
(defconstant +mem-commit+ #x001000)
(defconstant +mem-reserve+ #x002000)
(defconstant +mem-decommit+ #x004000)
(defconstant +mem-release+ #x008000)
(defconstant +mem-free+ #x010000)
(defconstant +mem-private+ #x020000)
(defconstant +mem-mapped+ #x040000)
(defconstant +mem-reset+ #x080000)
(defconstant +mem-top-down+ #x100000)

;heap allocation flags
(defconstant +heap-no-serialize+ 1)
(defconstant +heap-generate-exceptions+ 4)
(defconstant +heap-zero-memory+ 8)

;platform identifiers
(defconstant +ver-platform-win32s+ 0)
(defconstant +ver-platform-win32-windows+ 1)
(defconstant +ver-platform-win32-nt+ 2)

;getbinarytype return values
(defconstant +scs-32bit-binary+ 0)
(defconstant +scs-dos-binary+ 1)
(defconstant +scs-wow-binary+ 2)
(defconstant +scs-pif-binary+ 3)
(defconstant +scs-posix-binary+ 4)
(defconstant +scs-os216-binary+ 5)

;createprocess flags
(defconstant +debug-process+ #x001)
(defconstant +debug-only-this-process+ #x002)
(defconstant +create-suspended+ #x004)
(defconstant +detached-process+ #x008)
(defconstant +create-new-console+ #x010)
(defconstant +normal-priority-class+ #x020)
(defconstant +idle-priority-class+ #x040)
(defconstant +high-priority-class+ #x080)
(defconstant +realtime-priority-class+ #x100)
(defconstant +create-new-process-group+ #x200)
(defconstant +create-separate-wow-vdm+ #x800)

;thread priority values
(defconstant +thread-base-priority-min+ -2)
(defconstant +thread-base-priority-max+ 2)
(defconstant +thread-base-priority-lowrt+ 15)
(defconstant +thread-base-priority-idle+ -15)
(defconstant +thread-priority-lowest+ +thread-base-priority-min+)
(defconstant +thread-priority-below-normal+ (+ +thread-priority-lowest+ 1))
(defconstant +thread-priority-normal+ 0)
(defconstant +thread-priority-highest+ +thread-base-priority-max+)
(defconstant +thread-priority-above-normal+ (- +thread-priority-highest+ 1))
(defconstant +thread-priority-error-return+ #x7fffffff)
(defconstant +thread-priority-time-critical+ +thread-base-priority-lowrt+)
(defconstant +thread-priority-idle+ +thread-base-priority-idle+)

;startup flags
(defconstant +startf-useshowwindow+ #x001)
(defconstant +startf-usesize+ #x002)
(defconstant +startf-useposition+ #x004)
(defconstant +startf-usecountchars+ #x008)
(defconstant +startf-usefillattribute+ #x010)
(defconstant +startf-runfullscreen+ #x020)
(defconstant +startf-forceonfeedback+ #x040)
(defconstant +startf-forceofffeedback+ #x080)
(defconstant +startf-usestdhandles+ #x100)

;shutdown flags
(defconstant +shutdown-noretry+ #x1)

;loadlibraryex flags
(defconstant +dont-resolve-dll-references+ 1)
(defconstant +load-library-as-datafile+ 2)
(defconstant +load-with-altered-search-path+ 8)

;dll entry-point calls
(defconstant +dll-process-detach+ 0)
(defconstant +dll-process-attach+ 1)
(defconstant +dll-thread-attach+ 2)
(defconstant +dll-thread-detach+ 3)

;status codes
(defconstant +status-wait-0+ #x000000000)
(defconstant +status-abandoned-wait-0+ #x000000080)
(defconstant +status-user-apc+ #x0000000c0)
(defconstant +status-timeout+ #x000000102)
(defconstant +status-pending+ #x000000103)
(defconstant +status-datatype-misalignment+ #x080000002)
(defconstant +status-breakpoint+ #x080000003)
(defconstant +status-single-step+ #x080000004)
(defconstant +status-access-violation+ #x0c0000005)
(defconstant +status-in-page-error+ #x0c0000006)
(defconstant +status-no-memory+ #x0c0000017)
(defconstant +status-illegal-instruction+ #x0c000001d)
(defconstant +status-noncontinuable-exception+ #x0c0000025)
(defconstant +status-invalid-disposition+ #x0c0000026)
(defconstant +status-array-bounds-exceeded+ #x0c000008c)
(defconstant +status-float-denormal-operand+ #x0c000008d)
(defconstant +status-float-divide-by-zero+ #x0c000008e)
(defconstant +status-float-inexact-result+ #x0c000008f)
(defconstant +status-float-invalid-operation+ #x0c0000090)
(defconstant +status-float-overflow+ #x0c0000091)
(defconstant +status-float-stack-check+ #x0c0000092)
(defconstant +status-float-underflow+ #x0c0000093)
(defconstant +status-integer-divide-by-zero+ #x0c0000094)
(defconstant +status-integer-overflow+ #x0c0000095)
(defconstant +status-privileged-instruction+ #x0c0000096)
(defconstant +status-stack-overflow+ #x0c00000fd)
(defconstant +status-control-c-exit+ #x0c000013a)
(defconstant +wait-failed+ -1)
(defconstant +wait-object-0+ +status-wait-0+)
(defconstant +wait-abandoned+ +status-abandoned-wait-0+)
(defconstant +wait-abandoned-0+ +status-abandoned-wait-0+)
(defconstant +wait-timeout+ +status-timeout+)
(defconstant +wait-io-completion+ +status-user-apc+)
(defconstant +still-active+ +status-pending+)

;exception codes
(defconstant +exception-continuable+ 0)
(defconstant +exception-noncontinuable+ 1)
(defconstant +exception-access-violation+ +status-access-violation+)
(defconstant +exception-datatype-misalignment+ +status-datatype-misalignment+)
(defconstant +exception-breakpoint+ +status-breakpoint+)
(defconstant +exception-single-step+ +status-single-step+)
(defconstant +exception-array-bounds-exceeded+ +status-array-bounds-exceeded+)
(defconstant +exception-flt-denormal-operand+ +status-float-denormal-operand+)
(defconstant +exception-flt-divide-by-zero+ +status-float-divide-by-zero+)
(defconstant +exception-flt-inexact-result+ +status-float-inexact-result+)
(defconstant +exception-flt-invalid-operation+ +status-float-invalid-operation+)
(defconstant +exception-flt-overflow+ +status-float-overflow+)
(defconstant +exception-flt-stack-check+ +status-float-stack-check+)
(defconstant +exception-flt-underflow+ +status-float-underflow+)
(defconstant +exception-int-divide-by-zero+ +status-integer-divide-by-zero+)
(defconstant +exception-int-overflow+ +status-integer-overflow+)
(defconstant +exception-illegal-instruction+ +status-illegal-instruction+)
(defconstant +exception-priv-instruction+ +status-privileged-instruction+)
(defconstant +exception-in-page-error+ +status-in-page-error+)

;registry options
(defconstant +reg-option-reserved+ 0)
(defconstant +reg-option-non-volatile+ 0)
(defconstant +reg-option-volatile+ 1)
(defconstant +reg-option-create-link+ 2)
(defconstant +reg-option-backup-restore+ 4)
(defconstant +reg-created-new-key+ 1)
(defconstant +reg-opened-existing-key+ 2)
(defconstant +reg-whole-hive-volatile+ 1)
(defconstant +reg-refresh-hive+ 2)
(defconstant +reg-notify-change-name+ 1)
(defconstant +reg-notify-change-attributes+ 2)
(defconstant +reg-notify-change-last-set+ 4)
(defconstant +reg-notify-change-security+ 8)
(defconstant +reg-legal-change-filter+ (+ +reg-notify-change-name+ +reg-notify-change-attributes+ +reg-notify-change-last-set+ +reg-notify-change-security+))
(defconstant +reg-legal-option+ (+ +reg-option-reserved+ +reg-option-non-volatile+ +reg-option-volatile+ +reg-option-create-link+ +reg-option-backup-restore+))
(defconstant +reg-none+ 0)
(defconstant +reg-sz+ 1)
(defconstant +reg-expand-sz+ 2)
(defconstant +reg-binary+ 3)
(defconstant +reg-dword+ 4)
(defconstant +reg-dword-little-endian+ 4)
(defconstant +reg-dword-big-endian+ 5)
(defconstant +reg-link+ 6)
(defconstant +reg-multi-sz+ 7)
(defconstant +reg-resource-list+ 8)
(defconstant +reg-full-resource-descriptor+ 9)
(defconstant +reg-resource-requirements-list+ 10)

;registry access modes
(defconstant +key-query-value+ 1)
(defconstant +key-set-value+ 2)
(defconstant +key-create-sub-key+ 4)
(defconstant +key-enumerate-sub-keys+ 8)
(defconstant +key-notify+ #x10)
(defconstant +key-create-link+ #x20)
(defconstant +key-read+ (+ +standard-rights-read+ +key-query-value+ +key-enumerate-sub-keys+ +key-notify+ (- +synchronize+)))
(defconstant +key-write+ (+ +standard-rights-write+ +key-set-value+ +key-create-sub-key+ (- +synchronize+)))
(defconstant +key-execute+ +key-read+)
(defconstant +key-all-access+ (+ +standard-rights-all+ +key-query-value+ +key-set-value+ +key-create-sub-key+ +key-enumerate-sub-keys+ +key-notify+ +key-create-link+ (- +synchronize+)))

;predefined registry keys
(defconstant +hkey-classes-root+ #x80000000)
(defconstant +hkey-current-user+ #x80000001)
(defconstant +hkey-local-machine+ #x80000002)
(defconstant +hkey-users+ #x80000003)
(defconstant +hkey-performance-data+ #x80000004)
(defconstant +hkey-current-config+ #x80000005)
(defconstant +hkey-dyn-data+ #x80000006)

;formatmessage flags
(defconstant +format-message-allocate-buffer+ #x0100)
(defconstant +format-message-ignore-inserts+ #x0200)
(defconstant +format-message-from-string+ #x0400)
(defconstant +format-message-from-hmodule+ #x0800)
(defconstant +format-message-from-system+ #x1000)
(defconstant +format-message-argument-array+ #x2000)
(defconstant +format-message-max-width-mask+ #x00ff)

;language identifiers
(defconstant +lang-neutral+ #x00)
(defconstant +lang-bulgarian+ #x02)
(defconstant +lang-chinese+ #x04)
(defconstant +lang-croatian+ #x1a)
(defconstant +lang-czech+ #x05)
(defconstant +lang-danish+ #x06)
(defconstant +lang-dutch+ #x13)
(defconstant +lang-english+ #x09)
(defconstant +lang-finnish+ #x0b)
(defconstant +lang-french+ #x0c)
(defconstant +lang-german+ #x07)
(defconstant +lang-greek+ #x08)
(defconstant +lang-hungarian+ #x0e)
(defconstant +lang-icelandic+ #x0f)
(defconstant +lang-italian+ #x10)
(defconstant +lang-japanese+ #x11)
(defconstant +lang-korean+ #x12)
(defconstant +lang-norwegian+ #x14)
(defconstant +lang-polish+ #x15)
(defconstant +lang-portuguese+ #x16)
(defconstant +lang-romanian+ #x18)
(defconstant +lang-russian+ #x19)
(defconstant +lang-slovak+ #x1b)
(defconstant +lang-slovenian+ #x24)
(defconstant +lang-spanish+ #x0a)
(defconstant +lang-swedish+ #x1d)
(defconstant +lang-thai+ #x1e)
(defconstant +lang-turkish+ #x1f)

;sublanguage identifiers
(defconstant +sublang-neutral+ (ash #x00 10))
(defconstant +sublang-default+ (ash #x01 10))
(defconstant +sublang-sys-default+ (ash #x02 10))
(defconstant +sublang-chinese-traditional+ (ash #x01 10))
(defconstant +sublang-chinese-simplified+ (ash #x02 10))
(defconstant +sublang-chinese-hongkong+ (ash #x03 10))
(defconstant +sublang-chinese-singapore+ (ash #x04 10))
(defconstant +sublang-dutch+ (ash #x01 10))
(defconstant +sublang-dutch-belgian+ (ash #x02 10))
(defconstant +sublang-english-us+ (ash #x01 10))
(defconstant +sublang-english-uk+ (ash #x02 10))
(defconstant +sublang-english-aus+ (ash #x03 10))
(defconstant +sublang-english-can+ (ash #x04 10))
(defconstant +sublang-english-nz+ (ash #x05 10))
(defconstant +sublang-english-eire+ (ash #x06 10))
(defconstant +sublang-french+ (ash #x01 10))
(defconstant +sublang-french-belgian+ (ash #x02 10))
(defconstant +sublang-french-canadian+ (ash #x03 10))
(defconstant +sublang-french-swiss+ (ash #x04 10))
(defconstant +sublang-german+ (ash #x01 10))
(defconstant +sublang-german-swiss+ (ash #x02 10))
(defconstant +sublang-german-austrian+ (ash #x03 10))
(defconstant +sublang-italian+ (ash #x01 10))
(defconstant +sublang-italian-swiss+ (ash #x02 10))
(defconstant +sublang-norwegian-bokmal+ (ash #x01 10))
(defconstant +sublang-norwegian-nynorsk+ (ash #x02 10))
(defconstant +sublang-portuguese+ (ash #x02 10))
(defconstant +sublang-portuguese-brazilian+ (ash #x01 10))
(defconstant +sublang-spanish+ (ash #x01 10))
(defconstant +sublang-spanish-mexican+ (ash #x02 10))
(defconstant +sublang-spanish-modern+ (ash #x03 10))

;sorting identifiers
(defconstant +sort-default+ (ash 0 16))
(defconstant +sort-japanese-xjis+ (ash 0 16))
(defconstant +sort-japanese-unicode+ (ash 1 16))
(defconstant +sort-chinese-big5+ (ash 0 16))
(defconstant +sort-chinese-prcp+ (ash 0 16))
(defconstant +sort-chinese-unicode+ (ash 1 16))
(defconstant +sort-chinese-prc+ (ash 2 16))
(defconstant +sort-chinese-bopomofo+ (ash 3 16))
(defconstant +sort-korean-ksc+ (ash 0 16))
(defconstant +sort-korean-unicode+ (ash 1 16))
(defconstant +sort-german-phone-book+ (ash 1 16))
(defconstant +sort-hungarian-default+ (ash 0 16))
(defconstant +sort-hungarian-technical+ (ash 1 16))

;code pages
(defconstant +cp-acp+ #x0)
;default to ansi code page
(defconstant +cp-oemcp+ #x1)  
;default to oem code page
(defconstant +cp-maccp+ #x2)
;default to mac code page
(defconstant +cp-thread-acp+ #x3)
;current thread's ansi code page
(defconstant +cp-symbol+ #x42)
;symbol translations
(defconstant +cp-utf7+ #x65000)
;utf-7 translation
(defconstant +cp-utf8+ #x65001)
;utf-8 translation

;resource types
(defconstant +rt-cursor+ 1)
(defconstant +rt-bitmap+ 2)
(defconstant +rt-icon+ 3)
(defconstant +rt-menu+ 4)
(defconstant +rt-dialog+ 5)
(defconstant +rt-string+ 6)
(defconstant +rt-fontdir+ 7)
(defconstant +rt-font+ 8)
(defconstant +rt-accelerator+ 9)
(defconstant +rt-rcdata+ 10)
(defconstant +rt-messagetable+ 11)
(defconstant +rt-group-cursor+ 12)
(defconstant +rt-group-icon+ 14)
(defconstant +rt-version+ 16)
(defconstant +rt-dlginclude+ 17)
(defconstant +rt-plugplay+ 19)
(defconstant +rt-vxd+ 20)
(defconstant +rt-anicursor+ 21)
(defconstant +rt-aniicon+ 22)
(defconstant +rt-html+ 23)
(defconstant +rt-manifest+ 24)

;clipboard formats
(defconstant +cf-text+ #x001)
(defconstant +cf-bitmap+ #x002)
(defconstant +cf-metafilepict+ #x003)
(defconstant +cf-sylk+ #x004)
(defconstant +cf-dif+ #x005)
(defconstant +cf-tiff+ #x006)
(defconstant +cf-oemtext+ #x007)
(defconstant +cf-dib+ #x008)
(defconstant +cf-palette+ #x009)
(defconstant +cf-pendata+ #x00a)
(defconstant +cf-riff+ #x00b)
(defconstant +cf-wave+ #x00c)
(defconstant +cf-unicodetext+ #x00d)
(defconstant +cf-enhmetafile+ #x00e)
(defconstant +cf-hdrop+ #x00f)
(defconstant +cf-locale+ #x010)
(defconstant +cf-ownerdisplay+ #x080)
(defconstant +cf-dsptext+ #x081)
(defconstant +cf-dspbitmap+ #x082)
(defconstant +cf-dspmetafilepict+ #x083)
(defconstant +cf-dspenhmetafile+ #x08e)
(defconstant +cf-privatefirst+ #x200)
(defconstant +cf-privatelast+ #x2ff)
(defconstant +cf-gdiobjfirst+ #x300)
(defconstant +cf-gdiobjlast+ #x3ff)

;os types for version info
(defconstant +vos-unknown+ #x00000000)
(defconstant +vos-dos+ #x00010000)
(defconstant +vos-os216+ #x00020000)
(defconstant +vos-os232+ #x00030000)
(defconstant +vos-nt+ #x00040000)
(defconstant +vos-base+ #x00000000)
(defconstant +vos-windows16+ #x00000001)
(defconstant +vos-pm16+ #x00000002)
(defconstant +vos-pm32+ #x00000003)
(defconstant +vos-windows32+ #x00000004)
(defconstant +vos-dos-windows16+ #x00010001)
(defconstant +vos-dos-windows32+ #x00010004)
(defconstant +vos-os216-pm16+ #x00020002)
(defconstant +vos-os232-pm32+ #x00030003)
(defconstant +vos-nt-windows32+ #x00040004)

;file types for version info
(defconstant +vft-unknown+ #x00000000)
(defconstant +vft-app+ #x00000001)
(defconstant +vft-dll+ #x00000002)
(defconstant +vft-drv+ #x00000003)
(defconstant +vft-font+ #x00000004)
(defconstant +vft-vxd+ #x00000005)
(defconstant +vft-static-lib+ #x00000007)

;file subtypes for version info
(defconstant +vft2-unknown+ #x00000000)
(defconstant +vft2-drv-printer+ #x00000001)
(defconstant +vft2-drv-keyboard+ #x00000002)
(defconstant +vft2-drv-language+ #x00000003)
(defconstant +vft2-drv-display+ #x00000004)
(defconstant +vft2-drv-mouse+ #x00000005)
(defconstant +vft2-drv-network+ #x00000006)
(defconstant +vft2-drv-system+ #x00000007)
(defconstant +vft2-drv-installable+ #x00000008)
(defconstant +vft2-drv-sound+ #x00000009)
(defconstant +vft2-drv-comm+ #x0000000a)
(defconstant +vft2-drv-inputmethod+ #x0000000b)
(defconstant +vft2-drv-versioned-printer+ #x0000000c)
(defconstant +vft2-font-raster+ #x00000001)
(defconstant +vft2-font-vector+ #x00000002)
(defconstant +vft2-font-truetype+ #x00000003)

;console control signals
(defconstant +ctrl-c-event+ 0)
(defconstant +ctrl-break-event+ 1)
(defconstant +ctrl-close-event+ 2)
(defconstant +ctrl-logoff-event+ 5)
(defconstant +ctrl-shutdown-event+ 6)


;kernel32.dll function's

(cffi:defcfun (get-last-error "GetLastError" :convention :stdcall :library "kernel32.dll")
    :ulong)

(cffi:defcfun (format-message "FormatMessageW" :convention :stdcall :library "kernel32.dll")
    :ulong
    (dw-flags :ulong)
    (lp-source (:pointer :void))
    (dw-message-id :ulong)
    (dw-language-id :ulong)
    (lp-buffer (:pointer (:string :encoding :utf-16le)))
    (n-size :ulong)
    (arguments (:pointer :void)))

(cffi:defcfun (local-lock "LocalLock" :convention :stdcall :library "kernel32.dll")
    (:pointer :void)
    "Locks a local memory object and returns a pointer to the first byte of the object's memory block.
Note  The local functions are slower than other memory management functions and do not provide as many features. Therefore, new applications should use the heap functions.
hMem A handle to the local memory object. This handle is returned by either the LocalAlloc or LocalReAlloc function.
=> (:pointer :void)
If the function succeeds, the return value is a pointer to the first byte of the memory block.
If the function fails, the return value is NULL. To get extended error information, call GetLastError. "
    (h-mem :handle))

(cffi:defcfun (local-unlock "LocalUnlock" :convention :stdcall :library "kernel32.dll")
    :int
    "Decrements the lock count associated with a memory object that was allocated with LMEM_MOVEABLE. This function has no effect on memory objects allocated with LMEM_FIXED.
Note  The local functions are slower than other memory management functions and do not provide as many features. Therefore, new applications should use the heap functions.
hMem A handle to the local memory object. This handle is returned by either the LocalAlloc or LocalReAlloc function.
=> :int
If the memory object is still locked after decrementing the lock count, the return value is nonzero. If the memory object is unlocked after decrementing the lock count, the function returns zero and GetLastError returns NO_ERROR.
If the function fails, the return value is zero and GetLastError returns a value other than NO_ERROR. "
    (h-mem :handle))

(cffi:defcfun (local-free "LocalFree" :convention :stdcall :library "kernel32.dll")
    :handle
    "Frees the specified local memory object and invalidates its handle.
Note  The local functions are slower than other memory management functions and do not provide as many features. Therefore, new applications should use the heap functions.
hMem A handle to the local memory object. This handle is returned by either the LocalAlloc or LocalReAlloc function. It is not safe to free memory allocated with GlobalAlloc.
=> :handle
If the function succeeds, the return value is NULL.
If the function fails, the return value is equal to a handle to the local memory object. To get extended error information, call GetLastError. "
    (h-mem (:pointer :void)))

