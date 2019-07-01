import "restriction_account/account_restriction_types.cats"
import "transaction.cats"

# account address restriction modification
struct AccountAddressRestrictionModification
	inline AccountRestrictionModification
	value = Address

# binary layout for an account address restriction transaction
struct AccountAddressRestrictionTransactionBody
	# account restriction type
	restrictionType = AccountRestrictionType

	# number of modifications
	modificationsCount = uint8

	# account restriction modifications
	modifications = array(AccountAddressRestrictionModification, modificationsCount)

# binary layout for a non-embedded account address restriction transaction
struct AccountAddressRestrictionTransaction
	const uint8 version = 1
	const EntityType entityType = 0x4150

	inline Transaction
	inline AccountAddressRestrictionTransactionBody

# binary layout for an embedded account address restriction transaction
struct EmbeddedAccountAddressRestrictionTransaction
	inline EmbeddedTransaction
	inline AccountAddressRestrictionTransactionBody
