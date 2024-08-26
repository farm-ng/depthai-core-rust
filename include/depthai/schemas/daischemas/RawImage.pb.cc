// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: daischemas/RawImage.proto

#include "daischemas/RawImage.pb.h"

#include <algorithm>
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/extension_set.h"
#include "google/protobuf/wire_format_lite.h"
#include "google/protobuf/descriptor.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/reflection_ops.h"
#include "google/protobuf/wire_format.h"
#include "google/protobuf/generated_message_tctable_impl.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"
PROTOBUF_PRAGMA_INIT_SEG
namespace _pb = ::google::protobuf;
namespace _pbi = ::google::protobuf::internal;
namespace _fl = ::google::protobuf::internal::field_layout;
namespace dai {
namespace schemas {

inline constexpr RawImage::Impl_::Impl_(
    ::_pbi::ConstantInitialized) noexcept
      : _cached_size_{0},
        encoding_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        data_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        frame_id_(
            &::google::protobuf::internal::fixed_address_empty_string,
            ::_pbi::ConstantInitialized()),
        timestamp_{nullptr},
        width_{0u},
        height_{0u},
        step_{0u} {}

template <typename>
PROTOBUF_CONSTEXPR RawImage::RawImage(::_pbi::ConstantInitialized)
    : _impl_(::_pbi::ConstantInitialized()) {}
struct RawImageDefaultTypeInternal {
  PROTOBUF_CONSTEXPR RawImageDefaultTypeInternal() : _instance(::_pbi::ConstantInitialized{}) {}
  ~RawImageDefaultTypeInternal() {}
  union {
    RawImage _instance;
  };
};

PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT
    PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 RawImageDefaultTypeInternal _RawImage_default_instance_;
}  // namespace schemas
}  // namespace dai
static ::_pb::Metadata file_level_metadata_daischemas_2fRawImage_2eproto[1];
static constexpr const ::_pb::EnumDescriptor**
    file_level_enum_descriptors_daischemas_2fRawImage_2eproto = nullptr;
static constexpr const ::_pb::ServiceDescriptor**
    file_level_service_descriptors_daischemas_2fRawImage_2eproto = nullptr;
const ::uint32_t TableStruct_daischemas_2fRawImage_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(
    protodesc_cold) = {
    PROTOBUF_FIELD_OFFSET(::dai::schemas::RawImage, _impl_._has_bits_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::RawImage, _internal_metadata_),
    ~0u,  // no _extensions_
    ~0u,  // no _oneof_case_
    ~0u,  // no _weak_field_map_
    ~0u,  // no _inlined_string_donated_
    ~0u,  // no _split_
    ~0u,  // no sizeof(Split)
    PROTOBUF_FIELD_OFFSET(::dai::schemas::RawImage, _impl_.timestamp_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::RawImage, _impl_.frame_id_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::RawImage, _impl_.width_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::RawImage, _impl_.height_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::RawImage, _impl_.encoding_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::RawImage, _impl_.step_),
    PROTOBUF_FIELD_OFFSET(::dai::schemas::RawImage, _impl_.data_),
    0,
    ~0u,
    ~0u,
    ~0u,
    ~0u,
    ~0u,
    ~0u,
};

static const ::_pbi::MigrationSchema
    schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
        {0, 15, -1, sizeof(::dai::schemas::RawImage)},
};

static const ::_pb::Message* const file_default_instances[] = {
    &::dai::schemas::_RawImage_default_instance_._instance,
};
const char descriptor_table_protodef_daischemas_2fRawImage_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
    "\n\031daischemas/RawImage.proto\022\013dai.schemas"
    "\032\037google/protobuf/timestamp.proto\"\230\001\n\010Ra"
    "wImage\022-\n\ttimestamp\030\001 \001(\0132\032.google.proto"
    "buf.Timestamp\022\020\n\010frame_id\030\007 \001(\t\022\r\n\005width"
    "\030\002 \001(\007\022\016\n\006height\030\003 \001(\007\022\020\n\010encoding\030\004 \001(\t"
    "\022\014\n\004step\030\005 \001(\007\022\014\n\004data\030\006 \001(\014b\006proto3"
};
static const ::_pbi::DescriptorTable* const descriptor_table_daischemas_2fRawImage_2eproto_deps[1] =
    {
        &::descriptor_table_google_2fprotobuf_2ftimestamp_2eproto,
};
static ::absl::once_flag descriptor_table_daischemas_2fRawImage_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_daischemas_2fRawImage_2eproto = {
    false,
    false,
    236,
    descriptor_table_protodef_daischemas_2fRawImage_2eproto,
    "daischemas/RawImage.proto",
    &descriptor_table_daischemas_2fRawImage_2eproto_once,
    descriptor_table_daischemas_2fRawImage_2eproto_deps,
    1,
    1,
    schemas,
    file_default_instances,
    TableStruct_daischemas_2fRawImage_2eproto::offsets,
    file_level_metadata_daischemas_2fRawImage_2eproto,
    file_level_enum_descriptors_daischemas_2fRawImage_2eproto,
    file_level_service_descriptors_daischemas_2fRawImage_2eproto,
};

// This function exists to be marked as weak.
// It can significantly speed up compilation by breaking up LLVM's SCC
// in the .pb.cc translation units. Large translation units see a
// reduction of more than 35% of walltime for optimized builds. Without
// the weak attribute all the messages in the file, including all the
// vtables and everything they use become part of the same SCC through
// a cycle like:
// GetMetadata -> descriptor table -> default instances ->
//   vtables -> GetMetadata
// By adding a weak function here we break the connection from the
// individual vtables back into the descriptor table.
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_daischemas_2fRawImage_2eproto_getter() {
  return &descriptor_table_daischemas_2fRawImage_2eproto;
}
// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2
static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_daischemas_2fRawImage_2eproto(&descriptor_table_daischemas_2fRawImage_2eproto);
namespace dai {
namespace schemas {
// ===================================================================

class RawImage::_Internal {
 public:
  using HasBits = decltype(std::declval<RawImage>()._impl_._has_bits_);
  static constexpr ::int32_t kHasBitsOffset =
    8 * PROTOBUF_FIELD_OFFSET(RawImage, _impl_._has_bits_);
  static const ::google::protobuf::Timestamp& timestamp(const RawImage* msg);
  static void set_has_timestamp(HasBits* has_bits) {
    (*has_bits)[0] |= 1u;
  }
};

const ::google::protobuf::Timestamp& RawImage::_Internal::timestamp(const RawImage* msg) {
  return *msg->_impl_.timestamp_;
}
void RawImage::clear_timestamp() {
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  if (_impl_.timestamp_ != nullptr) _impl_.timestamp_->Clear();
  _impl_._has_bits_[0] &= ~0x00000001u;
}
RawImage::RawImage(::google::protobuf::Arena* arena)
    : ::google::protobuf::Message(arena) {
  SharedCtor(arena);
  // @@protoc_insertion_point(arena_constructor:dai.schemas.RawImage)
}
inline PROTOBUF_NDEBUG_INLINE RawImage::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility, ::google::protobuf::Arena* arena,
    const Impl_& from)
      : _has_bits_{from._has_bits_},
        _cached_size_{0},
        encoding_(arena, from.encoding_),
        data_(arena, from.data_),
        frame_id_(arena, from.frame_id_) {}

RawImage::RawImage(
    ::google::protobuf::Arena* arena,
    const RawImage& from)
    : ::google::protobuf::Message(arena) {
  RawImage* const _this = this;
  (void)_this;
  _internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(
      from._internal_metadata_);
  new (&_impl_) Impl_(internal_visibility(), arena, from._impl_);
  ::uint32_t cached_has_bits = _impl_._has_bits_[0];
  _impl_.timestamp_ = (cached_has_bits & 0x00000001u)
                ? CreateMaybeMessage<::google::protobuf::Timestamp>(arena, *from._impl_.timestamp_)
                : nullptr;
  ::memcpy(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, width_),
           reinterpret_cast<const char *>(&from._impl_) +
               offsetof(Impl_, width_),
           offsetof(Impl_, step_) -
               offsetof(Impl_, width_) +
               sizeof(Impl_::step_));

  // @@protoc_insertion_point(copy_constructor:dai.schemas.RawImage)
}
inline PROTOBUF_NDEBUG_INLINE RawImage::Impl_::Impl_(
    ::google::protobuf::internal::InternalVisibility visibility,
    ::google::protobuf::Arena* arena)
      : _cached_size_{0},
        encoding_(arena),
        data_(arena),
        frame_id_(arena) {}

inline void RawImage::SharedCtor(::_pb::Arena* arena) {
  new (&_impl_) Impl_(internal_visibility(), arena);
  ::memset(reinterpret_cast<char *>(&_impl_) +
               offsetof(Impl_, timestamp_),
           0,
           offsetof(Impl_, step_) -
               offsetof(Impl_, timestamp_) +
               sizeof(Impl_::step_));
}
RawImage::~RawImage() {
  // @@protoc_insertion_point(destructor:dai.schemas.RawImage)
  _internal_metadata_.Delete<::google::protobuf::UnknownFieldSet>();
  SharedDtor();
}
inline void RawImage::SharedDtor() {
  ABSL_DCHECK(GetArena() == nullptr);
  _impl_.encoding_.Destroy();
  _impl_.data_.Destroy();
  _impl_.frame_id_.Destroy();
  delete _impl_.timestamp_;
  _impl_.~Impl_();
}

PROTOBUF_NOINLINE void RawImage::Clear() {
// @@protoc_insertion_point(message_clear_start:dai.schemas.RawImage)
  PROTOBUF_TSAN_WRITE(&_impl_._tsan_detect_race);
  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.encoding_.ClearToEmpty();
  _impl_.data_.ClearToEmpty();
  _impl_.frame_id_.ClearToEmpty();
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    ABSL_DCHECK(_impl_.timestamp_ != nullptr);
    _impl_.timestamp_->Clear();
  }
  ::memset(&_impl_.width_, 0, static_cast<::size_t>(
      reinterpret_cast<char*>(&_impl_.step_) -
      reinterpret_cast<char*>(&_impl_.width_)) + sizeof(_impl_.step_));
  _impl_._has_bits_.Clear();
  _internal_metadata_.Clear<::google::protobuf::UnknownFieldSet>();
}

const char* RawImage::_InternalParse(
    const char* ptr, ::_pbi::ParseContext* ctx) {
  ptr = ::_pbi::TcParser::ParseLoop(this, ptr, ctx, &_table_.header);
  return ptr;
}


PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1
const ::_pbi::TcParseTable<3, 7, 1, 45, 2> RawImage::_table_ = {
  {
    PROTOBUF_FIELD_OFFSET(RawImage, _impl_._has_bits_),
    0, // no _extensions_
    7, 56,  // max_field_number, fast_idx_mask
    offsetof(decltype(_table_), field_lookup_table),
    4294967168,  // skipmap
    offsetof(decltype(_table_), field_entries),
    7,  // num_field_entries
    1,  // num_aux_entries
    offsetof(decltype(_table_), aux_entries),
    &_RawImage_default_instance_._instance,
    ::_pbi::TcParser::GenericFallback,  // fallback
  }, {{
    {::_pbi::TcParser::MiniParse, {}},
    // .google.protobuf.Timestamp timestamp = 1;
    {::_pbi::TcParser::FastMtS1,
     {10, 0, 0, PROTOBUF_FIELD_OFFSET(RawImage, _impl_.timestamp_)}},
    // fixed32 width = 2;
    {::_pbi::TcParser::FastF32S1,
     {21, 63, 0, PROTOBUF_FIELD_OFFSET(RawImage, _impl_.width_)}},
    // fixed32 height = 3;
    {::_pbi::TcParser::FastF32S1,
     {29, 63, 0, PROTOBUF_FIELD_OFFSET(RawImage, _impl_.height_)}},
    // string encoding = 4;
    {::_pbi::TcParser::FastUS1,
     {34, 63, 0, PROTOBUF_FIELD_OFFSET(RawImage, _impl_.encoding_)}},
    // fixed32 step = 5;
    {::_pbi::TcParser::FastF32S1,
     {45, 63, 0, PROTOBUF_FIELD_OFFSET(RawImage, _impl_.step_)}},
    // bytes data = 6;
    {::_pbi::TcParser::FastBS1,
     {50, 63, 0, PROTOBUF_FIELD_OFFSET(RawImage, _impl_.data_)}},
    // string frame_id = 7;
    {::_pbi::TcParser::FastUS1,
     {58, 63, 0, PROTOBUF_FIELD_OFFSET(RawImage, _impl_.frame_id_)}},
  }}, {{
    65535, 65535
  }}, {{
    // .google.protobuf.Timestamp timestamp = 1;
    {PROTOBUF_FIELD_OFFSET(RawImage, _impl_.timestamp_), _Internal::kHasBitsOffset + 0, 0,
    (0 | ::_fl::kFcOptional | ::_fl::kMessage | ::_fl::kTvTable)},
    // fixed32 width = 2;
    {PROTOBUF_FIELD_OFFSET(RawImage, _impl_.width_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFixed32)},
    // fixed32 height = 3;
    {PROTOBUF_FIELD_OFFSET(RawImage, _impl_.height_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFixed32)},
    // string encoding = 4;
    {PROTOBUF_FIELD_OFFSET(RawImage, _impl_.encoding_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
    // fixed32 step = 5;
    {PROTOBUF_FIELD_OFFSET(RawImage, _impl_.step_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kFixed32)},
    // bytes data = 6;
    {PROTOBUF_FIELD_OFFSET(RawImage, _impl_.data_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kBytes | ::_fl::kRepAString)},
    // string frame_id = 7;
    {PROTOBUF_FIELD_OFFSET(RawImage, _impl_.frame_id_), -1, 0,
    (0 | ::_fl::kFcSingular | ::_fl::kUtf8String | ::_fl::kRepAString)},
  }}, {{
    {::_pbi::TcParser::GetTable<::google::protobuf::Timestamp>()},
  }}, {{
    "\24\0\0\0\10\0\0\10"
    "dai.schemas.RawImage"
    "encoding"
    "frame_id"
  }},
};

::uint8_t* RawImage::_InternalSerialize(
    ::uint8_t* target,
    ::google::protobuf::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:dai.schemas.RawImage)
  ::uint32_t cached_has_bits = 0;
  (void)cached_has_bits;

  cached_has_bits = _impl_._has_bits_[0];
  // .google.protobuf.Timestamp timestamp = 1;
  if (cached_has_bits & 0x00000001u) {
    target = ::google::protobuf::internal::WireFormatLite::InternalWriteMessage(
        1, _Internal::timestamp(this),
        _Internal::timestamp(this).GetCachedSize(), target, stream);
  }

  // fixed32 width = 2;
  if (this->_internal_width() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFixed32ToArray(
        2, this->_internal_width(), target);
  }

  // fixed32 height = 3;
  if (this->_internal_height() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFixed32ToArray(
        3, this->_internal_height(), target);
  }

  // string encoding = 4;
  if (!this->_internal_encoding().empty()) {
    const std::string& _s = this->_internal_encoding();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "dai.schemas.RawImage.encoding");
    target = stream->WriteStringMaybeAliased(4, _s, target);
  }

  // fixed32 step = 5;
  if (this->_internal_step() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteFixed32ToArray(
        5, this->_internal_step(), target);
  }

  // bytes data = 6;
  if (!this->_internal_data().empty()) {
    const std::string& _s = this->_internal_data();
    target = stream->WriteBytesMaybeAliased(6, _s, target);
  }

  // string frame_id = 7;
  if (!this->_internal_frame_id().empty()) {
    const std::string& _s = this->_internal_frame_id();
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
        _s.data(), static_cast<int>(_s.length()), ::google::protobuf::internal::WireFormatLite::SERIALIZE, "dai.schemas.RawImage.frame_id");
    target = stream->WriteStringMaybeAliased(7, _s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target =
        ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
            _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:dai.schemas.RawImage)
  return target;
}

::size_t RawImage::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:dai.schemas.RawImage)
  ::size_t total_size = 0;

  ::uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string encoding = 4;
  if (!this->_internal_encoding().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_encoding());
  }

  // bytes data = 6;
  if (!this->_internal_data().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::BytesSize(
                                    this->_internal_data());
  }

  // string frame_id = 7;
  if (!this->_internal_frame_id().empty()) {
    total_size += 1 + ::google::protobuf::internal::WireFormatLite::StringSize(
                                    this->_internal_frame_id());
  }

  // .google.protobuf.Timestamp timestamp = 1;
  cached_has_bits = _impl_._has_bits_[0];
  if (cached_has_bits & 0x00000001u) {
    total_size +=
        1 + ::google::protobuf::internal::WireFormatLite::MessageSize(*_impl_.timestamp_);
  }

  // fixed32 width = 2;
  if (this->_internal_width() != 0) {
    total_size += 5;
  }

  // fixed32 height = 3;
  if (this->_internal_height() != 0) {
    total_size += 5;
  }

  // fixed32 step = 5;
  if (this->_internal_step() != 0) {
    total_size += 5;
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::google::protobuf::Message::ClassData RawImage::_class_data_ = {
    RawImage::MergeImpl,
    nullptr,  // OnDemandRegisterArenaDtor
};
const ::google::protobuf::Message::ClassData* RawImage::GetClassData() const {
  return &_class_data_;
}

void RawImage::MergeImpl(::google::protobuf::Message& to_msg, const ::google::protobuf::Message& from_msg) {
  auto* const _this = static_cast<RawImage*>(&to_msg);
  auto& from = static_cast<const RawImage&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:dai.schemas.RawImage)
  ABSL_DCHECK_NE(&from, _this);
  ::uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_encoding().empty()) {
    _this->_internal_set_encoding(from._internal_encoding());
  }
  if (!from._internal_data().empty()) {
    _this->_internal_set_data(from._internal_data());
  }
  if (!from._internal_frame_id().empty()) {
    _this->_internal_set_frame_id(from._internal_frame_id());
  }
  if ((from._impl_._has_bits_[0] & 0x00000001u) != 0) {
    _this->_internal_mutable_timestamp()->::google::protobuf::Timestamp::MergeFrom(
        from._internal_timestamp());
  }
  if (from._internal_width() != 0) {
    _this->_internal_set_width(from._internal_width());
  }
  if (from._internal_height() != 0) {
    _this->_internal_set_height(from._internal_height());
  }
  if (from._internal_step() != 0) {
    _this->_internal_set_step(from._internal_step());
  }
  _this->_internal_metadata_.MergeFrom<::google::protobuf::UnknownFieldSet>(from._internal_metadata_);
}

void RawImage::CopyFrom(const RawImage& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:dai.schemas.RawImage)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

PROTOBUF_NOINLINE bool RawImage::IsInitialized() const {
  return true;
}

::_pbi::CachedSize* RawImage::AccessCachedSize() const {
  return &_impl_._cached_size_;
}
void RawImage::InternalSwap(RawImage* PROTOBUF_RESTRICT other) {
  using std::swap;
  auto* arena = GetArena();
  ABSL_DCHECK_EQ(arena, other->GetArena());
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  swap(_impl_._has_bits_[0], other->_impl_._has_bits_[0]);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.encoding_, &other->_impl_.encoding_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.data_, &other->_impl_.data_, arena);
  ::_pbi::ArenaStringPtr::InternalSwap(&_impl_.frame_id_, &other->_impl_.frame_id_, arena);
  ::google::protobuf::internal::memswap<
      PROTOBUF_FIELD_OFFSET(RawImage, _impl_.step_)
      + sizeof(RawImage::_impl_.step_)
      - PROTOBUF_FIELD_OFFSET(RawImage, _impl_.timestamp_)>(
          reinterpret_cast<char*>(&_impl_.timestamp_),
          reinterpret_cast<char*>(&other->_impl_.timestamp_));
}

::google::protobuf::Metadata RawImage::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_daischemas_2fRawImage_2eproto_getter, &descriptor_table_daischemas_2fRawImage_2eproto_once,
      file_level_metadata_daischemas_2fRawImage_2eproto[0]);
}
// @@protoc_insertion_point(namespace_scope)
}  // namespace schemas
}  // namespace dai
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google
// @@protoc_insertion_point(global_scope)
#include "google/protobuf/port_undef.inc"
